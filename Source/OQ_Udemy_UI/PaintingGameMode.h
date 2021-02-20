// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PaintingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API APaintingGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	void Load();
	void Save(); // saving from here because game mode know the slot

protected:
	void BeginPlay() override;

public:
	FString GetSlotName() { return SlotName; }

private:
	FString SlotName;
	
};
