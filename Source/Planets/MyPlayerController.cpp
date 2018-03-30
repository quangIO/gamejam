// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "PlanetsPawn.h"

void AMyPlayerController::UpdateRotation()
{
	FHitResult HitResult;
	GetHitResultUnderCursorByChannel(TraceTypeQuery3, false, HitResult);
	if (HitResult.bBlockingHit) 
	{
		APawn *ControlledPawn = GetPawn();
		const FRotator rot = UKismetMathLibrary::FindLookAtRotation(ControlledPawn->GetActorLocation(), HitResult.Location);
		ControlledPawn->SetActorRotation(rot);
	}
}




