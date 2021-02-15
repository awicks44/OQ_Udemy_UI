// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HandControllerBase.generated.h"

UCLASS()
class OQ_UDEMY_UI_API AHandControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandControllerBase();

protected:
	

public:	
	virtual void SetHand(EControllerHand Hand);
	virtual void TriggerPressed();
	virtual void TriggerReleased();

private: 
	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent *MotionController;
};
