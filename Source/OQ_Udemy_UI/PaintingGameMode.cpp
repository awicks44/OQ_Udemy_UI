// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Saving/VRSaveGame.h"

void APaintingGameMode::InitGame(const FString & MapName, const FString & Options, FString & ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);	

	SlotName = UGameplayStatics::ParseOption(Options, TEXT("SlotName"));

	UE_LOG(LogTemp, Warning, TEXT("Game Mode Init -> Slot Name: %s"), *SlotName);
}

void APaintingGameMode::Save()
{
	UVRSaveGame *Painting = UVRSaveGame::Load(SlotName);
	if (Painting)
	{
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
	}
}


void APaintingGameMode::Load()
{
	UVRSaveGame *SG = UVRSaveGame::Load(SlotName);
	if (SG)
	{
		SG->DeserializeToWorld(GetWorld());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Mode - Load: Game Slot Not found %s"), *SlotName);
	}
}


void APaintingGameMode::BeginPlay()
{
	Super::BeginPlay();	

	Load();

	UStereoLayerFunctionLibrary::HideSplashScreen();
}