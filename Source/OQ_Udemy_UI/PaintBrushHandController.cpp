// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintBrushHandController.h"
#include "Engine/World.h"


// Sets default values
APaintBrushHandController::APaintBrushHandController()
{
	//AHandControllerBase::AHandControllerBase();

	PrimaryActorTick.bCanEverTick = true;
	
}

void APaintBrushHandController::BeginPlay()
{
	Super::BeginPlay();
}

void APaintBrushHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentStroke)
	{
		CurrentStroke->Update(GetActorLocation());
	}	
}

void APaintBrushHandController::TriggerPressed()
{
	//AHandControllerBase::TriggerPressed();

	if (StrokeChildClass)
	{
		CurrentStroke = GetWorld()->SpawnActor<AStroke>(StrokeChildClass);
		if (CurrentStroke != nullptr)
		{
			CurrentStroke->SetActorLocation(GetActorLocation());
		}
	}
}

void APaintBrushHandController::TriggerReleased()
{
	//AHandControllerBase::TriggerReleased();

	CurrentStroke = nullptr;
}


