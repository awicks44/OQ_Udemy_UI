// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaintBrushHandController.h"
#include "HandControllerBase.h"
#include "VRPawn.generated.h"

UCLASS()
class OQ_UDEMY_UI_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPawn();

protected:
	// Called when the game starts or wPaintBrushHandControllerChildClasshen spawned
	virtual void BeginPlay() override;

private: 
	void RightTriggerPressed();
	void RightTriggerReleased() { RightController->TriggerReleased(); }	
	void PaginateRightAxis(float AxisValue);
	void UpdateCurrentPage(int32 Offset);

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent *Camera;
	
	UPROPERTY()
	AHandControllerBase *RightController;

	UPROPERTY()
	AHandControllerBase *LeftController;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent *VRRoot;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> RightHandControllerChildClass;	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> LeftHandControllerChildClass;

	UPROPERTY(EditDefaultsOnly)
		float PaginationThumbstickThreshold;

	int32 LastPaginationValue = 0;

	



};
