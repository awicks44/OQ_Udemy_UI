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
	SetRootComponent(Root);

	StrokeMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StrokeMeshes"));
	StrokeMeshes->SetupAttachment(Root);

	JointMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("JointMeshes"));
	JointMeshes->SetupAttachment(Root);
}

void AStroke::Update(FVector CursorLocation)
{
	if (PreviousCursorLocation.IsNearlyZero())
	{
		PreviousCursorLocation = CursorLocation;
		JointMeshes->AddInstance(GetNextJointTransform(CursorLocation));
		return;
	}

	StrokeMeshes->AddInstance(GetNextSegmentTransform(CursorLocation));

	PreviousCursorLocation = CursorLocation;

	// will
	JointMeshes->AddInstance(GetNextJointTransform(CursorLocation));
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

FTransform AStroke::GetNextJointTransform(FVector CurrentLocation) const
{
	FTransform JointTransform;

	JointTransform.SetLocation(GetTransform().InverseTransformPosition(CurrentLocation));

	return JointTransform;
}

FVector AStroke::GetNextSegmentScale(FVector CurrentLocation) const
{
	// in order to get the distance between 2 vectors, subtract the vectors then use the size method
	// this gives us the size, but only along the 'x' axis of scale	
	FVector Segment = CurrentLocation - PreviousCursorLocation; // space between point A & point B on the graph

	return FVector(Segment.Size(), 1, 1);
}

FQuat AStroke::GetNextSegmentRotation(FVector CurrentLocation) const
{
	// need to get the segment
	FVector Segment = CurrentLocation - PreviousCursorLocation;
	// direction w/ out the length. Of Unit length (1)
	FVector SegmentNormal = Segment.GetSafeNormal();
	// need to find the rotation between the forward vector and the segment normal
	return FQuat::FindBetweenNormals(FVector::ForwardVector, SegmentNormal);
}

FVector AStroke::GetNextSegmentLocation(FVector CurrentLocation) const
{
	// next segment will need to convert the previous location world space to local space
	return GetTransform().InverseTransformPosition(PreviousCursorLocation);
}



