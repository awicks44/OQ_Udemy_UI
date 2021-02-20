// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Saving/VRSaveGame.h"

void APaintingGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);	

	SlotName = UGameplayStatics::ParseOption(Options, TEXT("SlotName"));

	UE_LOG(LogTemp, Warning, TEXT("Data is %s"), *SlotName);
}

void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();

	UVRSaveGame *SG = UVRSaveGame::Load(SlotName);
	if (SG)
	{
		SG->DeserializeToWorld(GetWorld());

		UStereoLayerFunctionLibrary::HideSplashScreen();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Slot Not found %s"), *SlotName);
	}
}