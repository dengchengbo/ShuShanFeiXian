// Fill out your copyright notice in the Description page of Project Settings.


#include "SFPlayerController.h"
#include "AbilityModule/Base/BaseAttributeSet.h"

ASFPlayerController::ASFPlayerController(const FObjectInitializer& ObjectInitializer)
{
	//AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));
}

void ASFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

