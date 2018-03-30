// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbitalComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "CustomGameState.h"
#include "StarBase.h"
#include "Engine/World.h"


void UOrbitalComponent::SetAllStars()
{
	Stars = Cast<ACustomGameState>(GetWorld()->GetGameState())->Stars;
}

// Sets default values for this component's properties
UOrbitalComponent::UOrbitalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	Parent = GetOwner();
	if (Parent)
		MeshComponent = Parent->FindComponentByClass<UStaticMeshComponent>();
}


// Called when the game starts
void UOrbitalComponent::BeginPlay()
{
	Super::BeginPlay();

	SetAllStars();

	// ...
	
}


// Called every frame
void UOrbitalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector Force(.0f, .0f, .0f);
	for (auto &s : Stars)
	{
		FVector r = (s->GetActorLocation() - Parent->GetActorLocation()) * DistanceFactor;
		Force += s->mass * MeshComponent->GetMass() * r.GetSafeNormal2D() / r.SizeSquared2D();
		// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, Force.ToString() + " and " + FString::SanitizeFloat(r.SizeSquared2D()) + " and " + r.GetSafeNormal2D().ToString());
	}

	MeshComponent->AddForce(ForceFactor * Force);
	// ...
}

