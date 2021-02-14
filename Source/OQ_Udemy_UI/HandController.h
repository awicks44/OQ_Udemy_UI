// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.h"
#include "HandController.generated.h"

UCLASS()
class OQ_UDEMY_UI_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void SetHand(EControllerHand Hand);
	void TriggerPressed();
	void TriggerReleased();

private: 

	UPROPERTY(VisibleAnywhere)
	class UMotionControllerComponent *MotionController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeChildClass;

	// state
	AStroke *CurrentStroke;
};
