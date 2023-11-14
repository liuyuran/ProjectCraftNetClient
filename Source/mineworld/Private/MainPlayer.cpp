// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"

#include "KeyBindUtils.h"

DEFINE_LOG_CATEGORY(LogCharacter)

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogCharacter, Display, TEXT("main charactor loaded!"));
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ReSharper disable once CppMemberFunctionMayBeStatic
void AMainPlayer::Test()
{
	UE_LOG(LogCharacter, Display, TEXT("key pressed!"));
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	FKeyBindUtils::AddAction("InventorySlotOne", EKeys::X, false, false, false);
	PlayerInputComponent->BindAction("InventorySlotOne", IE_Pressed, this, &AMainPlayer::Test);
	UE_LOG(LogCharacter, Display, TEXT("key binded!"));
}

