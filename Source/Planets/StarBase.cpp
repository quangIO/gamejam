// Fill out your copyright notice in the Description page of Project Settings.

#include "StarBase.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AStarBase::AStarBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	// Create mesh component for the projectile sphere
	StarMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StarMesh"));
	StarMeshComponent->SetupAttachment(RootComponent);
	StarMeshComponent->SetCollisionObjectType(ECC_WorldStatic);
	StarMeshComponent->SetMobility(EComponentMobility::Static);
	StarMeshComponent->bGenerateOverlapEvents = false;

	RootComponent = StarMeshComponent;
}

// Called when the game starts or when spawned
void AStarBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

