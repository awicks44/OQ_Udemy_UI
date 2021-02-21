// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingPage.h"


void UPaintingPage::SetActive(bool Active)
{
	DotImage->SetOpacity(Active ? 1 : DisabledOpacity);
}
