// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxGameMode.h"

#include "MainPlayer.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "StartMenu.h"
#include "Blueprint/UserWidget.h"

ASandboxGameMode::ASandboxGameMode()
{
	DefaultPawnClass = AMainPlayer::StaticClass();
}

void ASandboxGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("game start!"));
	CreateWidget<UStartMenu>(GetWorld(), UStartMenu::StaticClass())->AddToViewport();
	// FSocket* Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	// const TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	// bool bIsValid;
	// Addr->SetIp(TEXT("127.0.0.1"), bIsValid);
	// Addr->SetPort(12345);
	// Socket->Connect(*Addr);
}

void ASandboxGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASandboxGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogTemp, Display, TEXT("游戏停止! %d"), EndPlayReason);
}
