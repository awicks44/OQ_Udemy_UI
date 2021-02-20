// Fill out your copyright notice in the Description page of Project Settings.


#include "PalleteMenuHandController.h"

APalleteMenuHandController::APalleteMenuHandController()
{
	PaletteMenu = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaletteMenu"));
	PaletteMenu->SetupAttachment(GetRootComponent());
}