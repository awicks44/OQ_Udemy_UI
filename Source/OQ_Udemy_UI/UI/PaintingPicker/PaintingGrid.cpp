// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "Components/SizeBox.h"

void UPaintingGrid::AddPainting(int32 PaintingIdx)
{
	if (!PaintingGrid) return;	
	
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetWorld(), GridCardClass);
	if (!NewWidget) return;

	USizeBox *CardContainer = Cast<USizeBox>(PaintingGrid->GetChildAt(PaintingIdx));
	if (!CardContainer) return;

	CardContainer->AddChild(NewWidget);
}
