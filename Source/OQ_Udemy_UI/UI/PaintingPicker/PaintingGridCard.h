// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PaintingGridCard.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UPaintingGridCard : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UTextBlock *SlotName;
	
};
