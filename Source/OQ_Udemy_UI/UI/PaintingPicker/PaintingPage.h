// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "PaintingPage.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UPaintingPage : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UImage *DotImage;

public: 
	void SetActive(bool Active);

private:
	UPROPERTY(EditDefaultsOnly)
	float DisabledOpacity = .5;

	
};
