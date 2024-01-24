// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkWorld.h"

#include "Chunk/ChunkBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChunkWorld::AChunkWorld()
{
	ChunkCount = 0;
	GenerationType = EGenerationType::GT_3D;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AChunkWorld::BeginPlay()
{
	Super::BeginPlay();
}

void AChunkWorld::RenderChunk(const int ChunkX, const int ChunkY, const int Distance, const int RenderLimit)
{
	int Limit = 0;
	for (int x = ChunkX - Distance; x <= ChunkX + Distance; x++)
	{
		for (int y = ChunkY - Distance; y <= ChunkY + Distance; ++y)
		{
			if (Chunks.Contains(FVector(x, y, 0)) || (RenderLimit > 0 && Limit >= RenderLimit))
			{
				continue;
			}
			auto Transform = FTransform(
				FRotator::ZeroRotator,
				FVector(x * Size * 100, y * Size * 100, 0),
				FVector::OneVector
			);
			const auto Chunk = GetWorld()->SpawnActorDeferred<AChunkBase>(
				ChunkType,
				Transform,
				this
			);
			Chunk->GenerationType = EGenerationType::GT_2D;
			Chunk->Frequency = Frequency;
			Chunk->Material = Material;
			Chunk->Size = Size;
			UGameplayStatics::FinishSpawningActor(Chunk, Transform);
			Chunks.Add(FVector(x, y, 0), Chunk);
			Limit++;
		}
	}
}

void AChunkWorld::ClearOutOfSightChunks(int ChunkX, int ChunkY, int Distance)
{
	TArray<UE::Math::TVector<double>> WaitRemove;
	for (auto& Chunk : Chunks)
	{
		if (FMath::Abs(Chunk.Key.X - ChunkX) > Distance || FMath::Abs(Chunk.Key.Y - ChunkY) > Distance)
		{
			WaitRemove.Add(Chunk.Key);
		}
	}
	for (auto& Pos: WaitRemove)
	{
		AChunkBase* Target = Chunks[Pos];
		GetWorld()->DestroyActor(Target);
		Chunks.Remove(Pos);
	}
}

void AChunkWorld::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// Get player position
	const auto Position = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	const auto PositionScale = Size * 100;
	const int ChunkX = Position.X / PositionScale;
	const int ChunkY = Position.Y / PositionScale;
	// generate chunks around player
	RenderChunk(ChunkX, ChunkY, 1, -1);
	RenderChunk(ChunkX, ChunkY, DrawDistance, FrameRenderLimit);
	ClearOutOfSightChunks(ChunkX, ChunkY, DrawDistance);
}
