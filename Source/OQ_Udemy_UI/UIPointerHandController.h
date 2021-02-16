// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "UIPointerHandController.generated.h"

/**
 * 
 */
UCLASS()
class OQ_UDEMY_UI_API AUIPointerHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	AUIPointerHandController();

public:
	/*void Tick(float DeltaTime) override;*/
	void TriggerPressed() override;
	void TriggerReleased() override;
	
protected:
	//void BeginPlay() override;


private: 
	UPROPERTY(VisibleAnywhere)
		class UWidgetInteractionComponent * Pointer;
};
