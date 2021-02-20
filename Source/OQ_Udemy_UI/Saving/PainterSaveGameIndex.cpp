// Fill out your copyright notice in the Description page of Project Settings.


#include "PainterSaveGameIndex.h"
#include "Kismet/GameplayStatics.h"

const FString UPainterSaveGameIndex::SLOT_NAME = "PaintingIndex";

bool UPainterSaveGameIndex::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, SLOT_NAME, 0);	
}

void UPainterSaveGameIndex::AddSaveGame(UVRSaveGame * GameToBeSaved)
{
	SlotNames.Add(GameToBeSaved->GetSlotName());
}

UPainterSaveGameIndex * UPainterSaveGameIndex::Load()
{
	auto Index = Cast< UPainterSaveGameIndex>(UGameplayStatics::LoadGameFromSlot(SLOT_NAME, 0));
	if (!Index)
	{
		UE_LOG(LogTemp, Warning, TEXT("UPainterSaveGameIndex Load: Cannot Load Painter Save Game "));
		Index = Cast<UPainterSaveGameIndex>(UGameplayStatics::CreateSaveGameObject(UPainterSaveGameIndex::StaticClass()));
		Index->Save();
	}
	
	return Index;
}
