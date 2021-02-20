// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "PaintingPicker.generated.h"

UCLASS()
class OQ_UDEMY_UI_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintingPicker();
	
	void AddPainting();
	void ToggleDeleteMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent *PaintingGrid;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent *ActionBar;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent *Root;

	void RefreshSlots();

};
