// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../HandControllerBase.h"
#include "Components/WidgetComponent.h"
#include "PalleteMenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API APalleteMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public: 
	APalleteMenuHandController();

private:
	//components
	UPROPERTY(VisibleAnywhere) // to edit in the ditor
	UWidgetComponent* PaletteMenu;
};
