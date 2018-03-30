// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StarBase.generated.h"

UCLASS()
class PLANETS_API AStarBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Appearance, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StarMeshComponent;
public:
	// Sets default values for this actor's properties
	AStarBase();

	UPROPERTY(EditAnywhere)
	float mass;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
