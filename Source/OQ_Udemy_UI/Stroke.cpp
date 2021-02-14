// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"
#include "Components/SplineMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	StrokeMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeMeshes"));
	StrokeMeshes->SetupAttachment(Root);
}

void AStroke::Update(FVector CursorLocation)
{
	FTransform NewStrokeTransform;

	// need to do this because the instance transform is in local space
	FVector LocalCursorLocation = GetTransform().InverseTransformPosition(CursorLocation);

	NewStrokeTransform.SetLocation(LocalCursorLocation);
	
	StrokeMeshes->AddInstance(NewStrokeTransform);	 	

	PreviousCursorLocation = CursorLocation;
}

FTransform AStroke::GetNextSegmentTransform(FVector CurrentLocation) const
{
	FTransform SegmentTransform;

	// all of these will be in local space
	SegmentTransform.SetScale3D(GetNextSegmentScale(CurrentLocation));
	SegmentTransform.SetRotation(GetNextSegmentRotation(CurrentLocation));
	SegmentTransform.SetLocation(GetNextSegmentLocation(CurrentLocation));

	// need to set the rotation & scale


	return SegmentTransform;
}

FVector AStroke::GetNextSegmentScale(FVector CurrentLocation) const
{
	return FVector();
}

FQuat AStroke::GetNextSegmentRotation(FVector CurrentLocation) const
{
	return FQuat();
}

FVector AStroke::GetNextSegmentLocation(FVector CurrentLocation) const
{
	// next segment will need to convert the previous location world space to local space
	return GetTransform().InverseTransformPosition(PreviousCursorLocation);
}



