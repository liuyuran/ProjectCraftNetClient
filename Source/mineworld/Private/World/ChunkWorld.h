// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Utils/Enums.h"

#include "ChunkWorld.generated.h"

class AChunkBase;

UCLASS()
class AChunkWorld final : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditInstanceOnly, Category="World")
	TSubclassOf<AChunkBase> ChunkType;
	
	UPROPERTY(EditInstanceOnly, Category="World")
	int DrawDistance = 5;

	UPROPERTY(EditInstanceOnly, Category="World")
	int FrameRenderLimit = 3;

	UPROPERTY(EditInstanceOnly, Category="Chunk")
	TObjectPtr<UMaterialInterface> Material;
	
	UPROPERTY(EditInstanceOnly, Category="Chunk")
	int Size = 32;

	UPROPERTY(EditInstanceOnly, Category="Height Map")
	EGenerationType GenerationType;

	UPROPERTY(EditInstanceOnly, Category="Height Map")
	float Frequency = 0.03f;
	
	// Sets default values for this actor's properties
	AChunkWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	int ChunkCount;
	TMap<FVector, AChunkBase*> Chunks;
	
	void RenderChunk(int ChunkX, int ChunkY, int Distance, int RenderLimit);
	void ClearOutOfSightChunks(int ChunkX, int ChunkY, int Distance);
};
