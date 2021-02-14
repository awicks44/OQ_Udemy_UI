// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stroke.generated.h"

UCLASS()
class OQ_UDEMY_UI_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStroke();
	
	void Update(FVector CursorLocation);	

private: 

	FTransform GetNextSegmentTransform(FVector CurrentLocation) const;
	FTransform GetNextJointTransform(FVector CurrentLocation) const;
	FVector GetNextSegmentScale(FVector CurrentLocation) const;
	FQuat GetNextSegmentRotation(FVector CurrentLocation) const;
	FVector GetNextSegmentLocation(FVector CurrentLocation) const;


	// components
	UPROPERTY(VisibleAnywhere)
	class USceneComponent *Root;	

	FVector PreviousCursorLocation;

	UPROPERTY(VisibleAnywhere)
	class UInstancedStaticMeshComponent *StrokeMeshes;

	UPROPERTY(VisibleAnywhere)
	class UInstancedStaticMeshComponent *JointMeshes;




};
