// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PaletteMenu.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UPaletteMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;
	
protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UButton* BackButton;

private:
	UFUNCTION()
	void BackButtonClicked();
};
