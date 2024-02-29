#include "NetworkController.h"

#include "Sockets.h"
#include "SocketSubsystem.h"

void FNetworkController::ConnectToServer(const TCHAR* Host, const int Port)
{
	if (bConnected) Disconnect();
	const TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool bIsValid;
	Addr->SetIp(Host, bIsValid);
	Addr->SetPort(Port);
	Socket->Connect(*Addr);
	Socket->SetNonBlocking(true);
	bConnected = true;
}

void FNetworkController::Disconnect()
{
	if (bConnected) Socket->Close();
	bConnected = false;
}

void FNetworkController::SendMsg(int Type, const FString& Buffer) const
{
	int32 BytesSent = 0;
	Socket->Send(reinterpret_cast<uint8*>(TCHAR_TO_UTF8(*Buffer)), Buffer.Len(), BytesSent);
}

FNetworkController::FNetworkController()
{
	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	bConnected = false;
}
