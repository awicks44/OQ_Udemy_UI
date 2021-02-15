// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.h"
#include "HandControllerBase.h"
#include "PaintBrushHandController.generated.h"

UCLASS()
class OQ_UDEMY_UI_API APaintBrushHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	APaintBrushHandController();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	
	void TriggerPressed() override;
	void TriggerReleased() override;

private: 	

	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeChildClass;

	// state
	AStroke *CurrentStroke;
};
