// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PlanetsGameMode.h"
#include "PlanetsPawn.h"

APlanetsGameMode::APlanetsGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = APlanetsPawn::StaticClass();
}

