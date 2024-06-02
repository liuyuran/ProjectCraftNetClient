#pragma once

#include "CoreMinimal.h"
#include "Utils/TThreadSafeQueue.h"

class FNetworkController;

enum EPackType
{
	// 未知消息
	UnknownPack = -1,
	// 关闭服务器
	ShutdownPack = 0,
	// 用户连入
	ConnectPack = 1,
	// 方块注册表
	BlockDefinePack = 2,
	// 聊天数据发送
	ChatPack = 3,
	// 心跳包
	PingPack = 4,
	// 服务器状态
	ServerStatusPack = 5,
	// 背包信息
	InventoryPack = 6,
	// 区块数据发送
	ChunkPack = 100,
	// 方块交互
	ControlBlockPack = 101,
	// 实体交互
	ControlEntityPack = 102,
	// 用户移动
	MovePack = 103,
	// 在线用户列表
	OnlineListPack = 104,
	// 断开连接
	DisconnectPack = 105,
	// 方块变化
	BlockChangePack = 106,
};

class FNetworkControllerReceiver final : FRunnable
{
public:
	FSocket* Socket;
	FNetworkController* Controller;
	virtual uint32 Run() override;
	void OnTcpReceiveMessage(int Type, const uint8* Buffer, size_t Len);
};

/**
 * 网络单例类
 */
class FNetworkController
{
public:
	static FNetworkController& GetInstance() {
		static FNetworkController Instance;
		return Instance;
	}
	TThreadSafeQueue<FString> MessageQueue;
	void ConnectToServer(const TCHAR* Host, int Port);
	void Destroy();
	void Disconnect();
	void HeartBeat() const;
	void Login(const FString& Username, const FString& Password) const;
	void Chat(const FString& Message) const;
	void FetchServerStatus() const;
	void FetchChunkData(int WorldId, int X, int Y, int Z) const;
protected:
	void SendMsg(int Type, const uint8* Buffer, size_t Len) const;
private:
	bool bConnected;
	FSocket* Socket;
	FNetworkControllerReceiver* Receiver;
	FRunnableThread* Thread;
	FNetworkController();
};
