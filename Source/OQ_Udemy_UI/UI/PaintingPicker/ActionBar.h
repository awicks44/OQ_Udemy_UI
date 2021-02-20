// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UButton *AddButton;

	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
	class UButton *TrashButton;

private:
	UFUNCTION()
	void AddButtonClicked();

	UFUNCTION()
	void TrashButtonClicked();


};
