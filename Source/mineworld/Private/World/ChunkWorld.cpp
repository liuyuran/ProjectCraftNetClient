// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"

#include "Chunk/ChunkBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChunkWorld::AChunkWorld()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ChunkCount = 0;
	GenerationType = EGenerationType::GT_3D;
}

// Called when the game starts or when spawned
void AChunkWorld::BeginPlay()
{
	Super::BeginPlay();
	
	switch (GenerationType)
	{
	case EGenerationType::GT_3D:
		Generate3DWorld();
		break;
	case EGenerationType::GT_2D:
		Generate2DWorld();
		break;
	default:
		throw std::invalid_argument("Invalid Generation Type");
	}

	UE_LOG(LogTemp, Warning, TEXT("%d Chunks Created"), ChunkCount);
}

void AChunkWorld::Generate3DWorld()
{
	for (int x = -DrawDistance; x <= DrawDistance; x++)
	{
		for (int y = -DrawDistance; y <= DrawDistance; ++y)
		{
			for (int z = -DrawDistance; z <= DrawDistance; ++z)
			{
				auto Transform = FTransform(
					FRotator::ZeroRotator,
					FVector(x * Size * 100, y * Size * 100, z * Size * 100),
					FVector::OneVector
				);

				const auto Chunk = GetWorld()->SpawnActorDeferred<AChunkBase>(
					ChunkType,
					Transform,
					this
				);

				Chunk->GenerationType = EGenerationType::GT_3D;
				Chunk->Frequency = Frequency;
				Chunk->Material = Material;
				Chunk->Size = Size;

				UGameplayStatics::FinishSpawningActor(Chunk, Transform);

				ChunkCount++;
			}
		}
	}
}

void AChunkWorld::Generate2DWorld()
{
	for (int x = -DrawDistance; x <= DrawDistance; x++)
	{
		for (int y = -DrawDistance; y <= DrawDistance; ++y)
		{
			auto transform = FTransform(
				FRotator::ZeroRotator,
				FVector(x * Size * 100, y * Size * 100, 0),
				FVector::OneVector
			);

			const auto chunk = GetWorld()->SpawnActorDeferred<AChunkBase>(
				ChunkType,
				transform,
				this
			);

			chunk->GenerationType = EGenerationType::GT_2D;
			chunk->Frequency = Frequency;
			chunk->Material = Material;
			chunk->Size = Size;

			UGameplayStatics::FinishSpawningActor(chunk, transform);

			ChunkCount++;
		}
	}
}
