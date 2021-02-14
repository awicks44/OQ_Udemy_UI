// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

}

void AStroke::Update(FVector CursorLocation)
{
	// 
	USplineMeshComponent *Spline = CreateSplineMesh();

	// we can just get the transform because we know the spline is at the root of our handle controller
	// transforming the cursor location which is in global space to local space. The stroke is local to the handle controller
	FVector StartPosition = GetActorTransform().InverseTransformPosition(CursorLocation);
	
	// the things that was last updated
	// we can use the previous cursor and update it after the end of the updatings
	FVector EndPosition = GetActorTransform().InverseTransformPosition(PreviousCursorLocation);

	Spline->SetStartAndEnd(StartPosition, FVector::ZeroVector, EndPosition, FVector::ZeroVector);

	PreviousCursorLocation = CursorLocation;
}

USplineMeshComponent * AStroke::CreateSplineMesh()
{

	USplineMeshComponent * NewSpline = NewObject<USplineMeshComponent>(this);
	NewSpline->SetMobility(EComponentMobility::Movable);	
	NewSpline->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale);	
	NewSpline->SetStaticMesh(SplineMesh);
	NewSpline->SetMaterial(0, SplineMaterial);
	NewSpline->RegisterComponent();

	return NewSpline;

	//

	//FVector startLocation, startTangent;
	//FVector endLocation, endTangent;

	//TeleportPath->GetLocalLocationAndTangentAtSplinePoint(i, startLocation, startTangent);
	//TeleportPath->GetLocalLocationAndTangentAtSplinePoint(i + 1, endLocation, endTangent);

	//SplineMesh->SetStartAndEnd(startLocation, FVector, endLocation, endTangent);
}
