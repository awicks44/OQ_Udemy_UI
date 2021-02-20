// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetTouchingComponent.h"
#include "Components/WidgetInteractionComponent.h"

void UWidgetTouchingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsOverInteractableWidget() && !bIsClicking)
	{
		Clicked();
	}
	
	if (!IsOverInteractableWidget() && bIsClicking)
	{
		Released();
	}
}

void UWidgetTouchingComponent::Clicked()
{
	PressPointerKey(EKeys::LeftMouseButton);
	bIsClicking = true;
}

void UWidgetTouchingComponent::Released()
{
	ReleasePointerKey(EKeys::LeftMouseButton);
	bIsClicking = false;
}
