// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxGameMode.h"

#include "MainPlayer.h"

ASandboxGameMode::ASandboxGameMode()
{
	DefaultPawnClass = AMainPlayer::StaticClass();
}

void ASandboxGameMode::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("game start!"));
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
