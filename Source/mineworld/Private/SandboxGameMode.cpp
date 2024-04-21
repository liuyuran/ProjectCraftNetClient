// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxGameMode.h"

#include "CustomHUD.h"
#include "MainPlayer.h"
#include "NetworkController.h"

ASandboxGameMode::ASandboxGameMode()
{
	DefaultPawnClass = AMainPlayer::StaticClass();
	HUDClass = ACustomHUD::StaticClass();
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	TotalTick = 0;
}

void ASandboxGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("游戏启动！"));
	FNetworkController::GetInstance().ConnectToServer(TEXT("127.0.0.1"), 13000);
	TotalTick = 0;
}

void ASandboxGameMode::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TotalTick += DeltaSeconds;
	if (TotalTick >= .5)
	{
		TotalTick = 0;
		FNetworkController::GetInstance().HeartBeat();
	}
}

void ASandboxGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UE_LOG(LogTemp, Display, TEXT("游戏停止! %d"), EndPlayReason);
	FNetworkController::GetInstance().Disconnect();
}
