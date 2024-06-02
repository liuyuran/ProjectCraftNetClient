#include "NetworkController.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "proto/core.pb.h"
#include "proto/server.pb.h"

FNetworkController::FNetworkController()
{
	Socket = nullptr;
	bConnected = false;
	Receiver = new FNetworkControllerReceiver();
	Thread = nullptr;
}

// ReSharper disable once CppMemberFunctionMayBeConst
void FNetworkControllerReceiver::OnTcpReceiveMessage(const int Type, const uint8* Buffer, size_t Len)
{
	UE_LOG(LogTemp, VeryVerbose, TEXT("收到服务器消息: %d"), Type);
	switch (static_cast<EPackType>(Type))
	{
	case ShutdownPack:
		// TODO 服务器关闭，退出登录
		break;
	case ConnectPack:
		{
			// 登录成功，获取区块数据
			for (int x = -3; x <= 3; x++)
			{
				for (int y = -3; y <= 3; y++)
				{
					for (int z = -3; z <= 3; z++)
					{
						Controller->FetchChunkData(0, x, y, z);
					}
				}
			}
			break;
		}
	case BlockDefinePack:
		{
			BlockDefine BlockDefine;
			BlockDefine.ParseFromArray(Buffer, Len);
			// 添加到全局变量
			const int Length = BlockDefine.items_size();
			for (int i = 0; i < Length; i++)
			{
				BlockDefineItem Item = BlockDefine.items(i);
			}
			break;
		}
	case ChatPack:
		break;
	case PingPack:
		break;
	case ServerStatusPack:
		break;
	case ChunkPack:
		{
			// 获取World实例，并将数据注入其中
			break;
		}
	case ControlBlockPack:
		break;
	case ControlEntityPack:
		break;
	case MovePack:
		break;
	case OnlineListPack:
		break;
	case DisconnectPack:
		break;
	case BlockChangePack:
		break;
	default:
		break;
	}
}

uint32 FNetworkControllerReceiver::Run()
{
	uint8 Bytes[1024];
	std::list<uint8> MsgBuffer = {};
	bool NewPack = true;
	uint32 PackLen = 0;
	uint32 PackType = 0;
	int32 Size = 0;
	while (Socket != nullptr)
	{
		if (Socket->Wait(ESocketWaitConditions::WaitForRead, FTimespan::FromSeconds(3)))
		{
			if (Socket == nullptr) return 1;
			for (int i = 0; i < 1024; i++)
			{
				Bytes[i] = 0;
			}
			if (Size = 0; Socket->Recv(Bytes, sizeof(Bytes), Size))
			{
				if (Size == 0) continue;
			}
			if (NewPack)
			{
				uint8 Tmp[4];
				// 读取包长度
				Tmp[0] = Bytes[3];
				Tmp[1] = Bytes[2];
				Tmp[2] = Bytes[1];
				Tmp[3] = Bytes[0];
				PackLen = Tmp[0] << 24 | Tmp[1] << 16 | Tmp[2] << 8 | Tmp[3];
				// 读取包类型
				Tmp[0] = Bytes[7];
				Tmp[1] = Bytes[6];
				Tmp[2] = Bytes[5];
				Tmp[3] = Bytes[4];
				PackType = Tmp[0] << 24 | Tmp[1] << 16 | Tmp[2] << 8 | Tmp[3];
				NewPack = false;
			}
			// 读取字节直到抵达第一个字节所标注的长度，下一次读取需要剔除所有的0
			for (int i = 0; i < Size; i++)
			{
				MsgBuffer.push_back(Bytes[i]);
				if (MsgBuffer.size() < PackLen + 8) continue;
				NewPack = true;

				// 剔除前八个字节
				for (int j = 0; j < 8; j++)
				{
					MsgBuffer.pop_front();
				}

				uint8* Msg = new uint8[MsgBuffer.size()];
				for (int j = 0; j < MsgBuffer.size(); j++)
				{
					Msg[j] = MsgBuffer.front();
					MsgBuffer.pop_front();
				}
				OnTcpReceiveMessage(PackType, Msg, MsgBuffer.size());
				delete[] Msg;
				MsgBuffer.clear();
				// 把剩下的数据塞进去
				for (int j = i + 1; j < Size; j++)
				{
					MsgBuffer.push_back(Bytes[j]);
				}

				break;
			}
		}
	}
	return 1;
}

void FNetworkController::ConnectToServer(const TCHAR* Host, const int Port)
{
	if (bConnected) return;
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	const TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool bIsValid;
	Addr->SetIp(Host, bIsValid);
	if (!bIsValid)
	{
		UE_LOG(LogTemp, Error, TEXT("连接服务器失败，主机名称不合法：%s"), Host);
		return;
	}
	Addr->SetPort(Port);
	if (!Socket->Connect(*Addr))
	{
		UE_LOG(LogTemp, Error, TEXT("连接服务器失败，错误原因：%s"), *Addr->ToString(true));
		return;
	}
	Socket->SetNoDelay(true);
	Socket->SetNonBlocking(false);
	if (Thread != nullptr)
	{
		Thread->Kill(false);
		delete Thread;
	}
	Receiver->Socket = Socket;
	Receiver->Controller = this;
	Thread = FRunnableThread::Create(reinterpret_cast<FRunnable*>(Receiver), TEXT("TcpReceiveThread"), 0, TPri_Normal);
	Login(TEXT("kamoeth"), TEXT("123456"));
	bConnected = true;
}

void FNetworkController::Destroy()
{
	Socket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	Socket = nullptr;
}

void FNetworkController::Disconnect()
{
	if (Thread != nullptr)
	{
		Thread->Kill(false);
		Receiver->Socket = nullptr;
		delete Thread;
		Thread = nullptr;
	}
	if (bConnected)
	{
		SendMsg(105, nullptr, 0);
		Socket->Close();
	}
	bConnected = false;
	Destroy();
}

void FNetworkController::HeartBeat() const
{
	uint8* Buffer = new uint8[8];
	const long Mill = FDateTime::UtcNow().ToUnixTimestamp() * 1000;
	FMemory::Memcpy(Buffer, &Mill, 8);
	SendMsg(4, Buffer, 8);
	delete[] Buffer;
}

void FNetworkController::Login(const FString& Username, const FString& Password) const
{
	Connect Connect;
	Connect.set_username(TCHAR_TO_UTF8(*Username));
	Connect.set_password(TCHAR_TO_UTF8(*Password));
	Connect.set_client_type(1);
	uint8* Buffer = new uint8[Connect.ByteSizeLong()];
	Connect.SerializeToArray(Buffer, Connect.ByteSizeLong());
	SendMsg(1, Buffer, Connect.ByteSizeLong());
	delete[] Buffer;
	UE_LOG(LogTemp, Display, TEXT("发送数据包：登录(length=%llu)"), Connect.ByteSizeLong());
}

void FNetworkController::Chat(const FString& Message) const
{
	ChatAndBroadcast Chat;
	Chat.set_msg(TCHAR_TO_UTF8(*Message));
	uint8* Buffer = new uint8[Chat.ByteSizeLong()];
	Chat.SerializeToArray(Buffer, Chat.ByteSizeLong());
	SendMsg(3, Buffer, Chat.ByteSizeLong());
	delete[] Buffer;
	UE_LOG(LogTemp, Display, TEXT("发送数据包：聊天(length=%llu)"), Chat.ByteSizeLong());
}

void FNetworkController::FetchServerStatus() const
{
	const ServerStatus Status;
	uint8* Buffer = new uint8[Status.ByteSizeLong()];
	Status.SerializeToArray(Buffer, Status.ByteSizeLong());
	SendMsg(5, Buffer, Status.ByteSizeLong());
	delete[] Buffer;
	UE_LOG(LogTemp, Display, TEXT("发送数据包：获取服务器状态(length=%llu)"), Status.ByteSizeLong());
}

void FNetworkController::FetchChunkData(const int WorldId, const int X, const int Y, const int Z) const
{
	ChunkData Data;
	Data.set_x(X);
	Data.set_y(Y);
	Data.set_z(Z);
	Data.set_worldid(WorldId);
	uint8* Buffer = new uint8[Data.ByteSizeLong()];
	Data.SerializeToArray(Buffer, Data.ByteSizeLong());
	SendMsg(100, Buffer, Data.ByteSizeLong());
	delete[] Buffer;
	UE_LOG(LogTemp, Display, TEXT("发送数据包：获取区块数据(length=%llu)"), Data.ByteSizeLong());
}

void FNetworkController::SendMsg(const int Type, const uint8* Buffer, const size_t Len) const
{
	if (Socket->GetConnectionState() != SCS_Connected)
	{
		UE_LOG(LogTemp, Error, TEXT("发送数据包失败，连接已断开"));
		return;
	}
	uint8* SendBuffer = new uint8[Len + 8];
	uint8* TmpBuffer = new uint8[4];
	const int IntLen = static_cast<int>(Len);
	FMemory::Memcpy(TmpBuffer, &IntLen, 4);
	SendBuffer[0] = TmpBuffer[3];
	SendBuffer[1] = TmpBuffer[2];
	SendBuffer[2] = TmpBuffer[1];
	SendBuffer[3] = TmpBuffer[0];
	FMemory::Memcpy(TmpBuffer, &Type, 4);
	SendBuffer[4] = TmpBuffer[3];
	SendBuffer[5] = TmpBuffer[2];
	SendBuffer[6] = TmpBuffer[1];
	SendBuffer[7] = TmpBuffer[0];
	if (Len > 0)
	{
		FMemory::Memcpy(SendBuffer + 8, Buffer, Len);
	}
	int32 BytesSent = 0;
	Socket->Send(SendBuffer, Len + 8, BytesSent);
	delete[] SendBuffer;
}
