// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PaintingPicker.h"
#include "ActionBar.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API UActionBar : public UUserWidget
{
	GENERATED_BODY()

public:
	
	bool Initialize() override;

	void SetParentPicker(APaintingPicker * NewParentPicker) { ParentPicker = NewParentPicker; }

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UButton *AddButton;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UButton *TrashButton;

private:
	UFUNCTION()
	void AddButtonClicked() { if (ParentPicker) ParentPicker->AddPainting(); }

	UFUNCTION()
	void TrashButtonClicked() { if (ParentPicker) ParentPicker->ToggleDeleteMode(); }

	UPROPERTY()
	APaintingPicker *ParentPicker;


};
