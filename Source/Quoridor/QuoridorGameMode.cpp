// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "QuoridorGameMode.h"
#include "QuoridorPlayerController.h"
#include "QuoridorPawn.h"

AQuoridorGameMode::AQuoridorGameMode()
{
	// no pawn by default
	DefaultPawnClass = AQuoridorPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AQuoridorPlayerController::StaticClass();
}
