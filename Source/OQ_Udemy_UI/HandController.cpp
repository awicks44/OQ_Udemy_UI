// Fill out your copyright notice in the Description page of Project Settings.


#include "HandController.h"
#include "Engine/World.h"
#include "MotionControllerComponent.h"

// Sets default values
AHandController::AHandController()
{
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetShowDeviceModel(true);
	SetRootComponent(MotionController);
}

void AHandController::BeginPlay()
{
	Super::BeginPlay();
}

void AHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}

	
}

void AHandController::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}

void AHandController::TriggerPressed()
{
	if (StrokeChildClass)
	{
		CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeChildClass);
		if (CurrentStroke != nullptr)
		{
			CurrentStroke->SetActorLocation(GetActorLocation());
		}
	}
}

void AHandController::TriggerReleased()
{
	CurrentStroke = nullptr;
}


