// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "PaintingGridCard.h"
#include "PaintingPage.h"
#include "Components/HorizontalBox.h"
#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()
		
public:
	UFUNCTION(BlueprintCallable)
	void AddPainting(int32 PaintingIdx, FString PaintingName);
	void AddPaintingPage(bool Active);
	void ClearPaintings();
	int32 GetNumberOfSlots() const;

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UUniformGridPanel *PaintingGrid;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	UHorizontalBox* PaginationPages;

private: 
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaintingGridCard> GridCardClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPaintingPage> PaintingPageClass;

	UPROPERTY(EditDefaultsOnly)
	float PaintingPageDotPadding = 8;
};
