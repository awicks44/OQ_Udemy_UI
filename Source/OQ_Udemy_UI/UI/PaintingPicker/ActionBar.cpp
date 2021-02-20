// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionBar.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"


bool UActionBar::Initialize() 
{
	if (!Super::Initialize()) return false;

	if (!AddButton) return false;	
	AddButton->OnClicked.AddDynamic(this, &UActionBar::AddButtonClicked);

	if (!TrashButton) return false;
	TrashButton->OnClicked.AddDynamic(this, &UActionBar::TrashButtonClicked);
	
	return true;
}

void UActionBar::AddButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("add button"));
}

void UActionBar::TrashButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("trash button"));
}
