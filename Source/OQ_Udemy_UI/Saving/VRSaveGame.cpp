// Fill out your copyright notice in the Description page of Project Settings.


#include "VRSaveGame.h"
#include "Kismet/GameplayStatics.h"

UVRSaveGame * UVRSaveGame::Create()
{
	UVRSaveGame *SaveGame = Cast<UVRSaveGame>(UGameplayStatics::CreateSaveGameObject(UVRSaveGame::StaticClass()));
	return SaveGame;
	
}

bool UVRSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}
