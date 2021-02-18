 // Fill out your copyright notice in the Description page of Project Settings.


#include "VRSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "../Stroke.h"
#include "Misc/Guid.h"


UVRSaveGame * UVRSaveGame::Create()
{
	UVRSaveGame *SaveGame = Cast<UVRSaveGame>(UGameplayStatics::CreateSaveGameObject(UVRSaveGame::StaticClass()));
	SaveGame->SlotName = FGuid::NewGuid().ToString();
	return SaveGame;
	
}

bool UVRSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}

UVRSaveGame * UVRSaveGame::Load(FString SlotName)
{
	UVRSaveGame *SaveGame = Cast<UVRSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	
	return SaveGame;
}

void UVRSaveGame::SerializeFromWorld(UWorld * World)
{
	// clear the array first
	Strokes.Empty();
	// iterate over all strokes
	for (TActorIterator<AStroke> StrokeIterator(World); StrokeIterator; ++StrokeIterator)
	{
		// previously we were getting the actual STroke class and adding them to the strokes array
		Strokes.Add(StrokeIterator->SerializeToStruct());
	}
}

void UVRSaveGame::DeserializeToWorld(UWorld * World)
{
	// clear the world
	ClearWorld(World);
	// Stroke class will be the BP created in the engine
	for (FStrokeState StrokeState: Strokes)
	{
		AStroke::SpawnAndDeserializeFromStruct(World, StrokeState);
	}
	
}

void UVRSaveGame::ClearWorld(UWorld * World)
{
	for (TActorIterator<AStroke> StrokeIterator(World); StrokeIterator; ++StrokeIterator)
	{
		StrokeIterator->Destroy();

	}
}
