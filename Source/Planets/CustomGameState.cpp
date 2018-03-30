// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomGameState.h"
#include "StarBase.h"
#include "Kismet/GameplayStatics.h"

ACustomGameState::ACustomGameState() 
{

	TArray<AActor*> Temp;
	UGameplayStatics::GetAllActorsOfClass(this, AStarBase::StaticClass(), Temp);
	for (auto &t: Temp)
	{
		Stars.Add(Cast<AStarBase>(t));
	}
	//if (GEngine)
	// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}




