// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Saving/VRSaveGame.h"
#include "Stroke.generated.h"


UCLASS()
class OQ_UDEMY_UI_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStroke();
	
	void Update(FVector CursorLocation);	

	FStrokeState SerializeToStruct() const;
	// we make StrokeState const because the state may be very large. This is a static method because it's not actually happening on the instnace of a stroke. The stroke we will be 
	// deserializing will be coming from the file and not an instance of the world
	static AStroke *SpawnAndDeserializeFromStruct(UWorld * World, const FStrokeState& StrokeState);

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
	TArray<FVector> ControlPoints;

	UPROPERTY(VisibleAnywhere)
	class UInstancedStaticMeshComponent *StrokeMeshes;

	UPROPERTY(VisibleAnywhere)
	class UInstancedStaticMeshComponent *JointMeshes;




};
