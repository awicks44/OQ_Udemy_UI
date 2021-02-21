// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGridCard.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;

	SlotName->SetText(FText::FromString(PaintingName));

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked);
}

void UPaintingGridCard::CardButtonClicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen(); // if loading the next screen takes loing

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Mainmap"), true, "SlotName=" + PaintingName);
}