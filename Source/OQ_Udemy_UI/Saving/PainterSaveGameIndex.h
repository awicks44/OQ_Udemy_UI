// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "VRSaveGame.h"
#include "PainterSaveGameIndex.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UPainterSaveGameIndex : public USaveGame
{
	GENERATED_BODY()

public:
	
	static UPainterSaveGameIndex* Load(); // static because we need the pointer

	bool Save(); // will be on a particular index

	void AddSaveGame(UVRSaveGame* GameToBeSaved);

	TArray<FString> GetSlotNames() const { return SlotNames; } // const because we aren't editing the contents of the save game index

private:
	static const FString SLOT_NAME;

	UPROPERTY()
	TArray<FString> SlotNames;

	
};
