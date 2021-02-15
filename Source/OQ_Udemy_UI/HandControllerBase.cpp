// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerBase.h"
#include "MotionControllerComponent.h"

// Sets default values
AHandControllerBase::AHandControllerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetShowDeviceModel(true);
	SetRootComponent(MotionController);

}

void AHandControllerBase::SetHand(EControllerHand Hand)
{
	MotionController->SetTrackingSource(Hand);
}

void AHandControllerBase::TriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Hand Controller Base - TriggerPressed"));
}

void AHandControllerBase::TriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("Hand Controller Base - TriggerReleased"));
}


