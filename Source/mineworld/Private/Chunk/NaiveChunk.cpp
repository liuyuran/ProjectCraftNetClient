// Fill out your copyright notice in the Description page of Project Settings.


#include "NaiveChunk.h"

#include <stdexcept>

#include "MainPlayer.h"
#include "Utils/FastNoiseLite.h"

EBlock ANaiveChunk::GetBlockByFaceIndex(const int Index)
{
	const int32 BlockIndex = FaceToPoint.FindRef(Index);
	return Blocks[BlockIndex];
}

void ANaiveChunk::Setup()
{
	// Initialize Blocks
	Blocks.SetNum(Size * Size * Size);
}

void ANaiveChunk::Generate2DHeightMap(const FVector Position)
{
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			const float XPos = x + Position.X;
			const float YPos = y + Position.Y;

			const int Height = FMath::Clamp(FMath::RoundToInt((Noise->GetNoise(XPos, YPos) + 1) * Size / 2), 0, Size);

			for (int z = 0; z < Height; z++)
			{
				Blocks[GetBlockIndex(x,y,z)] = EBlock::Stone;
			}
			
			for (int z = Height; z < Size; z++)
			{
				Blocks[GetBlockIndex(x,y,z)] = EBlock::Air;
			}
		}
	}
}

void ANaiveChunk::Generate3DHeightMap(const FVector Position)
{
	for (int x = 0; x < Size; ++x)
	{
		for (int y = 0; y < Size; ++y)
		{
			for (int z = 0; z < Size; ++z)
			{
				const auto NoiseValue = Noise->GetNoise(x + Position.X, y + Position.Y, z + Position.Z);

				if (NoiseValue >= 0)
				{
					Blocks[GetBlockIndex(x, y, z)] = EBlock::Air;
				}
				else
				{
					Blocks[GetBlockIndex(x, y, z)] = EBlock::Stone;
				}
			}
		}
	}
}

void ANaiveChunk::GenerateMesh()
{
	FaceToPoint.Empty();
	for (int x = 0; x < Size; x++)
	{
		for (int y = 0; y < Size; y++)
		{
			for (int z = 0; z < Size; z++)
			{
				if (Blocks[GetBlockIndex(x,y,z)] != EBlock::Air)
				{
					const auto Position = FVector(x,y,z);
					
					for (auto Direction : {EDirection::Forward, EDirection::Right, EDirection::Back, EDirection::Left, EDirection::Up, EDirection::Down})
					{
						if (Check(GetPositionInDirection(Direction, Position)))
						{
							CreateFace(Direction, Position * 100);
						}
					}
				}
			}
		}
	}
}

bool ANaiveChunk::Check(const FVector Position) const
{
	if (Position.X >= Size || Position.Y >= Size || Position.X < 0 || Position.Y < 0 || Position.Z < 0) return true;
	if (Position.Z >= Size) return true;
	return Blocks[GetBlockIndex(Position.X, Position.Y, Position.Z)] == EBlock::Air;
}

void ANaiveChunk::CreateFace(const EDirection Direction, const FVector Position)
{
	const auto Color = FColor::MakeRandomColor();
	const auto Normal = GetNormal(Direction);

	FaceToPoint.Add(MeshData.Vertices.Num(), GetBlockIndex(Position.X, Position.Y, Position.Z));
	MeshData.Vertices.Append(GetFaceVertices(Direction, Position));
	// 一个面对应两个三角形
	const auto TruthPos = Position / 100;
	FaceToPoint.Add(MeshData.Triangles.Num() / 3, GetBlockIndex(TruthPos.X, TruthPos.Y, TruthPos.Z));
	FaceToPoint.Add(MeshData.Triangles.Num() / 3 + 1, GetBlockIndex(TruthPos.X, TruthPos.Y, TruthPos.Z));
	// 实际填入三角形顶点数据，这里是三个点确定一个三角形，所以上面必须除三
	MeshData.Triangles.Append({ VertexCount + 3, VertexCount + 2, VertexCount, VertexCount + 2, VertexCount + 1, VertexCount });
	MeshData.Normals.Append({Normal, Normal, Normal, Normal});
	MeshData.Colors.Append({Color, Color, Color, Color});
	switch (Direction)
	{
	case EDirection::Back:// FORWARD?
		MeshData.UV0.Append({
			FVector2D(0, 0.5),
			FVector2D(0.333, 0.5),
			FVector2D(0.333, 1),
			FVector2D(0, 1)
		});
		break;
	case EDirection::Right:
		MeshData.UV0.Append({
			FVector2D(0.666, 0),
			FVector2D(1, 0),
			FVector2D(1, 0.5),
			FVector2D(0.666, 0.5)
		});
		break;
	case EDirection::Forward: // BACK?
		MeshData.UV0.Append({
			FVector2D(0.666, 0.5),
			FVector2D(1, 0.5),
			FVector2D(1, 1),
			FVector2D(0.666, 1),
		});
		break;
	case EDirection::Up:
		MeshData.UV0.Append({
			FVector2D(0.333, 0.5),
			FVector2D(0.666, 0.5),
			FVector2D(0.666, 1),
			FVector2D(0.333, 1)
		});
		break;
	case EDirection::Left:
		MeshData.UV0.Append({
			FVector2D(0.333, 0),
			FVector2D(0.666, 0),
			FVector2D(0.666, 0.5),
			FVector2D(0.333, 0.5)
		});
		break;
	case EDirection::Down:
		MeshData.UV0.Append({
			FVector2D(0, 0),
			FVector2D(0.333, 0),
			FVector2D(0.333, 0.5),
			FVector2D(0, 0.5)
		});
		break;
	}
	VertexCount += 4;
}

TArray<FVector> ANaiveChunk::GetFaceVertices(EDirection Direction, const FVector Position) const
{
	TArray<FVector> Vertices;

	for (int i = 0; i < 4; i++)
	{
		Vertices.Add(BlockVertexData[BlockTriangleData[i + static_cast<int>(Direction) * 4]] + Position);
	}
	
	return Vertices;
}

FVector ANaiveChunk::GetPositionInDirection(const EDirection Direction, const FVector Position) const
{
	switch (Direction)
	{
	case EDirection::Forward: return Position + FVector::ForwardVector;
	case EDirection::Back: return Position + FVector::BackwardVector;
	case EDirection::Left: return Position + FVector::LeftVector;
	case EDirection::Right: return Position + FVector::RightVector;
	case EDirection::Up: return Position + FVector::UpVector;
	case EDirection::Down: return Position + FVector::DownVector;
	default: throw std::invalid_argument("Invalid direction");
	}
}

FVector ANaiveChunk::GetNormal(const EDirection Direction) const
{
	switch (Direction)
	{
	case EDirection::Forward: return FVector::ForwardVector;
	case EDirection::Right: return FVector::RightVector;
	case EDirection::Back: return FVector::BackwardVector;
	case EDirection::Left: return FVector::LeftVector;
	case EDirection::Up: return FVector::UpVector;
	case EDirection::Down: return FVector::DownVector;
	default: throw std::invalid_argument("Invalid direction");
	}
}

void ANaiveChunk::ModifyVoxelData(const FIntVector Position, const EBlock Block)
{
	const int Index = GetBlockIndex(Position.X, Position.Y, Position.Z);
	
	Blocks[Index] = Block;
}

int ANaiveChunk::GetBlockIndex(int X, int Y, int Z) const
{
	if (X > Size) X = X % Size;
	if (Y > Size) Y = Y % Size;
	if (Z > Size) Z = Z % Size;
	return Z * Size * Size + Y * Size + X;
}

FVector ANaiveChunk::GetBlockPosition(const int FaceIndex) const
{
	// TODO 坐标明显不对
	const int32 BlockIndex = FaceToPoint.FindRef(FaceIndex);
	const int32 X = BlockIndex % Size;
	const int32 Y = (BlockIndex / Size) % Size;
	const int32 Z = BlockIndex / (Size * Size);
	return FVector(X, Y, Z);
}
