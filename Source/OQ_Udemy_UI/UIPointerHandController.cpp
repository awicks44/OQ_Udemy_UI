// Fill out your copyright notice in the Description page of Project Settings.


#include "UIPointerHandController.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/WidgetComponent.h"
#include "InputCoreTypes.h"

AUIPointerHandController::AUIPointerHandController()
{
	//PrimaryActorTick.bCanEverTick = true;

	Pointer = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("Pointer"));
	Pointer->SetupAttachment(GetRootComponent());
}

void AUIPointerHandController::TriggerPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("AUIPointerHandController - TriggerPressed"));
	Pointer->PressPointerKey(EKeys::LeftMouseButton);
}

void AUIPointerHandController::TriggerReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("AUIPointerHandController - TriggerReleased"));
	Pointer->ReleasePointerKey(EKeys::LeftMouseButton);
}
