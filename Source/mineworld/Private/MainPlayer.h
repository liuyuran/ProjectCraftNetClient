// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "MainPlayer.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCharacter, Log, All);

UCLASS()
class AMainPlayer : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainPlayer();

protected:
	bool bIsPaused;
	TSubclassOf<UUserWidget> PauseWidgetClass;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Test();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};

