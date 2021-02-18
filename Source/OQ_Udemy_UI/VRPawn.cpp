// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"
#include "Camera/CameraComponent.h"
#include "Saving/VRSaveGame.h"

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

	// create a new painting every time the scene loads
	UVRSaveGame * Painting = UVRSaveGame::Create();
	if (Painting && Painting->Save())
	{
		CurrentSlotName = Painting->GetSlotName();
	}	

	if (PaintBrushHandControllerChildClass)
	{
		RightController = GetWorld()->SpawnActor<AHandControllerBase>(PaintBrushHandControllerChildClass);
		if (RightController != nullptr)
		{
			RightController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
			RightController->SetOwner(this);
			RightController->SetHand(EControllerHand::Right);
		}
	}	
}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);	

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), IE_Released, this, &AVRPawn::RightTriggerReleased);
	PlayerInputComponent->BindAction(TEXT("Save"), IE_Released, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), IE_Released, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	// when user saves, then load the current painting based on the stored slot name
	UVRSaveGame *Painting = UVRSaveGame::Load(CurrentSlotName);
	if (Painting)
	{
		Painting->SetState("Hello World");
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}	

	UE_LOG(LogTemp, Warning, TEXT("Saved Game"));
}

void AVRPawn::Load()
{
	UVRSaveGame *SG = UVRSaveGame::Load(CurrentSlotName);
	if (SG)
	{
		SG->DeserializeToWorld(GetWorld());		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Save Game NOT FOUND"));
	}
}



