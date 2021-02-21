// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Camera/CameraComponent.h"
#include "Saving/VRSaveGame.h"
#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PaintingPicker/PaintingPicker.h"
#include "EngineUtils.h"

// Sets default values
AVRPawn::AVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);
}

// Called when the game starts or when spawned
void AVRPawn::BeginPlay()
{
	Super::BeginPlay();	

	if (RightHandControllerChildClass)
	{
		RightController = GetWorld()->SpawnActor<AHandControllerBase>(RightHandControllerChildClass);
		if (RightController != nullptr)
		{
			RightController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
			RightController->SetOwner(this);
			RightController->SetHand(EControllerHand::Right);
		}
	}	

	if (LeftHandControllerChildClass)
	{
		LeftController = GetWorld()->SpawnActor<AHandControllerBase>(LeftHandControllerChildClass);
		if (LeftController != nullptr)
		{
			LeftController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
			LeftController->SetOwner(this);
			LeftController->SetHand(EControllerHand::Left);
		}
	}
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);	

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), IE_Released, this, &AVRPawn::RightTriggerReleased);	
	PlayerInputComponent->BindAxis(TEXT("PaginateRight"), this, &AVRPawn::PaginateRightAxis);
	
}

void AVRPawn::RightTriggerPressed()
{
	//UE_LOG(LogTemp, Warning, TEXT("VRPane Trigger")); 
	RightController->TriggerPressed();
}

void AVRPawn::PaginateRightAxis(float AxisValue)
{
	
	int32 PaginationValue = 0;
	// if axix value is greater than our threshold of .9, then 1 to PaginationValue
	PaginationValue += AxisValue > PaginationThumbstickThreshold ? 1 : 0;
	PaginationValue += AxisValue < -PaginationThumbstickThreshold ? -1 : 0;

	if (PaginationValue != LastPaginationValue && PaginationValue != 0)
	{
		UpdateCurrentPage(PaginationValue);
	}	

	LastPaginationValue = PaginationValue;
}

void AVRPawn::UpdateCurrentPage(int32 Offset)
{
	// loop through all actor of type APaintingPicker
	for (TActorIterator<APaintingPicker>PaintingPickerItr (GetWorld()); PaintingPickerItr; ++PaintingPickerItr)
	{
		PaintingPickerItr->UpdateCurrentPage(Offset);
	}
}


