// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingPicker.h"
#include "PaintingGrid.h"
#include "ActionBar.h"
#include "../../Saving/VRSaveGame.h"
#include "../../Saving/PainterSaveGameIndex.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
APaintingPicker::APaintingPicker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();		

	UActionBar *ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}
	
	Refresh();
	
}

void APaintingPicker::RefreshSlots()
{
	UE_LOG(LogTemp, Warning, TEXT("Nubmer of Pages: %d"), GetNumberOfPages());

	UPaintingGrid *PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) return;	

	PaintingGridWidget->ClearPaintings();

	int idx = 0;
	for (FString Slot : UPainterSaveGameIndex::Load()->GetSlotNames())
	{
		PaintingGridWidget->AddPainting(idx, Slot);
		idx++;
	}	
}

void APaintingPicker::RefreshDots()
{
	UPaintingGrid *PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPaginationDots();

	for (int i = 0; i < GetNumberOfPages(); i++)
	{
		// we can doa  cur
		PaintingGridWidget->AddPaintingPage(CurrentPage == i);
	}
}

void APaintingPicker::AddPainting()
{
	// create our initial save game, along with save game index
	UVRSaveGame::Create();

	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	UPaintingGrid *PaintingGridWidget = GetPaintingGrid();
	if (!PaintingGridWidget) return;

	PaintingGridWidget->ClearPaintings();
}


int32 APaintingPicker::GetNumberOfPages() const
{
	UPaintingGrid *PaintingGridWidget = GetPaintingGrid();
	
	if (!PaintingGridWidget) return 0;

	int32 TotalNumberOfSlots = UPainterSaveGameIndex::Load()->GetSlotNames().Num();
	
	int32 SlotsPerPage = PaintingGridWidget->GetNumberOfSlots();
	
	return FMath::CeilToFloat((float)TotalNumberOfSlots / SlotsPerPage);
}