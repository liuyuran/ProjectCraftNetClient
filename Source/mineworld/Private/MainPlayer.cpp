// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"

#include "KeyBindUtils.h"
#include "Chunk/NaiveChunk.h"
#include "Kismet/GameplayStatics.h"

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
	FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	FVector2D ScreenCenter = ViewportSize / 2.0f;
	FVector WorldLocation;
	FVector WorldDirection;
	UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0), ScreenCenter, WorldLocation, WorldDirection);
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	Params.bReturnFaceIndex = true;
	GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * 10000.0f, ECC_Visibility, Params);
	if (HitResult.bBlockingHit && HitResult.Distance <= 1000.0f)
	{
		if (AActor* TargetActor = HitResult.GetActor(); TargetActor->GetClass() == ANaiveChunk::StaticClass())
		{
			ANaiveChunk* TargetChunk = static_cast<ANaiveChunk*>(TargetActor);
			EBlock Block = TargetChunk->GetBlockByFaceIndex(HitResult.FaceIndex);
			FVector BlockPosition = TargetChunk->GetBlockPosition(HitResult.FaceIndex) + TargetActor->GetActorLocation() / 100;
			FString BlockName = UEnum::GetValueAsString(Block);
			UE_LOG(LogTemp, Warning, TEXT("Object %s [%d] [%f, %f, %f] is in the center of the screen and within 1000 units."),
				*BlockName, HitResult.FaceIndex, BlockPosition.X, BlockPosition.Y, BlockPosition.Z);
		}
	}
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// FKeyBindUtils::AddAction("InventorySlotOne", EKeys::X, false, false, false);
	// PlayerInputComponent->BindAction("InventorySlotOne", IE_Pressed, this, &AMainPlayer::Test);
	FKeyBindUtils::AddAction("InventorySlotTwo", EKeys::LeftMouseButton, false, false, false);
	PlayerInputComponent->BindAction("InventorySlotTwo", IE_Pressed, this, &AMainPlayer::Test);
	UE_LOG(LogCharacter, Display, TEXT("key binded!"));
}

