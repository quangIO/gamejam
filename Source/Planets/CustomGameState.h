// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StarBase.h"
#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "CustomGameState.generated.h"

/**
 * 
 */
UCLASS()
class PLANETS_API ACustomGameState : public AGameState
{
	GENERATED_BODY()
public:
	ACustomGameState();

	UPROPERTY(VisibleAnywhere)
	TArray<AStarBase*> Stars;
	
};
