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
	class USplineMeshComponent* CreateSplineMesh();

	// components
	UPROPERTY(VisibleAnywhere)
	class USceneComponent *Root;

	//config
	UPROPERTY(EditDefaultsOnly)
	class UStaticMesh *SplineMesh;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface *SplineMaterial;

	FVector PreviousCursorLocation;


};
