#pragma once

#include "CoreMinimal.h"

class FNetworkControllerReceiver final : FRunnable
{
public:
	FSocket* Socket;
	virtual uint32 Run() override;
	static void OnTcpReceiveMessage(const uint8* Buffer, size_t Len);
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
