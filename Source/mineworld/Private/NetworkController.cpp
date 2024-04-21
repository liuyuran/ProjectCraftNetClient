#include "NetworkController.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "proto/core.pb.h"
#include "proto/server.pb.h"

FNetworkController::FNetworkController()
{
	Socket = nullptr;
	bConnected = false;
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
