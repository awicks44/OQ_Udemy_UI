// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "Components/SizeBox.h"

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
