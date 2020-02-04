// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "QuoridorPlayerController.h"

AQuoridorPlayerController::AQuoridorPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Hand;
}
