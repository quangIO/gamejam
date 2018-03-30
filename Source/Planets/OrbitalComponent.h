// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StarBase.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitalComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLANETS_API UOrbitalComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UStaticMeshComponent* MeshComponent;
	TArray<AStarBase*> Stars;
	AActor* Parent;

	inline void SetAllStars();
public:	
	// Sets default values for this component's properties
	UOrbitalComponent();

	UPROPERTY(EditAnywhere)
	float ForceFactor = 1000.f;

	UPROPERTY(EditAnywhere)
	float DistanceFactor = 1.f;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
