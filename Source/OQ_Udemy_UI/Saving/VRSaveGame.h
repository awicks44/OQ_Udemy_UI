// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "VRSaveGame.generated.h"

USTRUCT()
struct FStrokeState
{
	GENERATED_BODY() // makes it work for UObject system

	UPROPERTY()
	// we need to put the state into UProperties
	// This is part of the 'state' that helps define what a 'stroke is'
	TSubclassOf<class AStroke> Class;

	// state of Stroke is also made up of Locations
	UPROPERTY()
	TArray<FVector> ControlPoints;
};
/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UVRSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	// Want something to save and something to create. This method is not on the instance because we haven't
	// create a USaveGame Yet. This method will create a new empty save game for use to populate with stuff
	static UVRSaveGame* Create();

	// we have a game now and we want to save it. 
	bool Save();

	static UVRSaveGame* Load(FString SlotName);

	void SetState(FString NewState) { State = NewState; }
	FString GetState() { return State; }

	// we aren't modifying the world pointer so we make the param pointe a const
	void SerializeFromWorld(UWorld * World);
	// we are going to take state and put it into the world. We are trying the world, so it won't be const
	void DeserializeToWorld(UWorld * World);

	FString GetSlotName() const { return SlotName; }
	
private: 
	UPROPERTY()
	FString State;

	UPROPERTY()
	FString SlotName;

	UPROPERTY()
	TArray<FStrokeState> Strokes;


private: 
	void ClearWorld(UWorld * World);
};
