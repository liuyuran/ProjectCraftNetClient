// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkBase.h"

#include <stdexcept>

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Utils/FastNoiseLite.h"
#include "ProceduralMeshComponent.h"
#include "Engine/VolumeTexture.h"


// Sets default values
AChunkBase::AChunkBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>("Mesh");
	Noise = new FastNoiseLite();

	// Mesh Settings
	Mesh->SetCastShadow(false);

	// Set Mesh as root
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AChunkBase::BeginPlay()
{
	Super::BeginPlay();

	Noise->SetFrequency(Frequency);
	Noise->SetNoiseType(FastNoiseLite::NoiseType_Perlin);
	Noise->SetFractalType(FastNoiseLite::FractalType_FBm);

	Setup();

	GenerateHeightMap();

	GenerateMesh();

	ApplyMesh();
}

void AChunkBase::GenerateHeightMap()
{
	switch (GenerationType)
	{
	case EGenerationType::GT_3D:
		Generate3DHeightMap(GetActorLocation() / 100);
		break;
	case EGenerationType::GT_2D:
		Generate2DHeightMap(GetActorLocation() / 100);
		break;
	default:
		throw std::invalid_argument("Invalid Generation Type");
	}
}

UMaterialInstanceDynamic* AChunkBase::LoadImageAsTexture(const FString& FilePath) const
{
	UTexture2D* MyTexture = nullptr;
	if (TArray64<uint8> RawFileData;
		FFileHelper::LoadFileToArray(RawFileData, FilePath.GetCharArray().GetData()))
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		// Note: PNG format.  Other formats are supported
		const TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
		{
			if (TArray64<uint8> UncompressedBGRA;
				ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
			{
				// Create the UTexture for rendering
				MyTexture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);
				// Fill in the source data from the file
				void* TextureData = MyTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());
				MyTexture->GetPlatformData()->Mips[0].BulkData.Unlock();
				// Update the rendering resource from data.
				MyTexture->UpdateResource();
			}
		}
	}
	if (!MyTexture) return nullptr;
	UMaterialInstanceDynamic* MyMaterialInstance = UMaterialInstanceDynamic::Create(Material, Mesh);
	MyMaterialInstance->ClearParameterValues();
	MyMaterialInstance->SetTextureParameterValue(FName("Texture"), MyTexture);
	return MyMaterialInstance;
}

void AChunkBase::ApplyMesh() const
{
	Mesh->SetMaterial(0, LoadImageAsTexture("F:/dirt.png"));
	Mesh->CreateMeshSection(
		0,
		MeshData.Vertices,
		MeshData.Triangles,
		MeshData.Normals,
		MeshData.UV0,
		MeshData.Colors,
		TArray<FProcMeshTangent>(),
		true
	);
}

void AChunkBase::ClearMesh()
{
	VertexCount = 0;
	MeshData.Clear();
}

void AChunkBase::ModifyVoxel(const FIntVector Position, const EBlock Block)
{
	if (Position.X >= Size || Position.Y >= Size || Position.Z >= Size || Position.X < 0 || Position.Y < 0 || Position.Z < 0) return;

	ModifyVoxelData(Position, Block);

	ClearMesh();

	GenerateMesh();

	ApplyMesh();
}
