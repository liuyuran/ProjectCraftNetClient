#pragma once

#include "CoreMinimal.h"

/**
 * 网络单例类
 */
class FNetworkController
{
public:
	static FNetworkController * const NetworkInstance;
	void ConnectToServer(const TCHAR* Host, int Port);
	void Disconnect();
	void SendMsg(int Type, const FString& Buffer) const;
private:
	bool bConnected;
	FSocket* Socket;
	FNetworkController();
};

FNetworkController * const FNetworkController::NetworkInstance = new FNetworkController();
