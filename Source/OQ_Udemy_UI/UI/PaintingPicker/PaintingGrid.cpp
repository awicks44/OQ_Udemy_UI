// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "Components/SizeBox.h"
#include "Components/PanelWidget.h"

void UPaintingGrid::AddPainting(int32 PaintingIdx, FString PaintingName)
{
	if (!PaintingGrid) return;	
	
	UPaintingGridCard* PaintingGridCard = CreateWidget<UPaintingGridCard>(GetWorld(), GridCardClass);
	if (!PaintingGridCard) return;

	PaintingGridCard->SetPaintingName(PaintingName);

	USizeBox *CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(PaintingIdx));
	if (!CardContainer) return;

	CardContainer->AddChild(PaintingGridCard);
}

void UPaintingGrid::ClearPaintings()
{
	for (int32 i = 0; i < PaintingGrid->GetChildrenCount(); i++)
	{
		USizeBox *CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(i));
		// if somehow a size box is not returned then skip this item and go to next loop iteration
		if (!CardContainer) continue;
		
		
		CardContainer->ClearChildren();
	}
}
