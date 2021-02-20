// Fill out your copyright notice in the Description page of Project Settings.


#include "PaletteMenu.h"
#include "Components/Button.h"
#include "../../PaintingGameMode.h"

bool UPaletteMenu::Initialize()
{
	if (!Super::Initialize())
	{
		UE_LOG(LogTemp, Warning, TEXT("PaletteMenu: COULD NOT SUPER INITIALIZE"));
		return false;
	}

	if (!BackButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("PaletteMenu: There was no back button"));
		return false;
	}
	
	BackButton->OnReleased.AddDynamic(this, &UPaletteMenu::BackButtonClicked);
	
	return true;
}

void UPaletteMenu::BackButtonClicked()
{
	
	auto GameMode = Cast<APaintingGameMode>(GetWorld()->GetAuthGameMode());

	GameMode->SaveAndQuit();
	
}