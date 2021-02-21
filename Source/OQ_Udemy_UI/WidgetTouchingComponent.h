// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetInteractionComponent.h"
#include "WidgetTouchingComponent.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class OQ_UDEMY_UI_API UWidgetTouchingComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()

public:	
	/*void OnComponentCreated() override;*/
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	void Clicked();
	void Released();


private:
	bool bIsClicking;

	
};
