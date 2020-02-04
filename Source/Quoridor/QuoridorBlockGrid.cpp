// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "QuoridorBlockGrid.h"
#include "QuoridorBlock.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AQuoridorBlockGrid::AQuoridorBlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Set defaults
	Size = 9;
	BlockSpacing = 300.f;
}


void AQuoridorBlockGrid::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex / Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex % Size) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		AQuoridorBlock* NewBlock = GetWorld()->SpawnActor<AQuoridorBlock>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		}
	}
}

#undef LOCTEXT_NAMESPACE
