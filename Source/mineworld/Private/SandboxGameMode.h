// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SandboxGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASandboxGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASandboxGameMode();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
};
