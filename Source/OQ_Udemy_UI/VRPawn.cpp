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

	if (HandControllerChildClass)
	{
		RightController = GetWorld()->SpawnActor<AHandController>(HandControllerChildClass);
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
	UVRSaveGame *SG = UVRSaveGame::Create();
	SG->SetState("Hello World");
	SG->Save();

	UE_LOG(LogTemp, Warning, TEXT("Saved Game"));
}

void AVRPawn::Load()
{
	UVRSaveGame *SG = UVRSaveGame::Load();	
	if (SG)
	{
		UE_LOG(LogTemp, Warning, TEXT("State is %s"), *SG->GetState());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Save Game NOT FOUND"));
	}

	

	
}

