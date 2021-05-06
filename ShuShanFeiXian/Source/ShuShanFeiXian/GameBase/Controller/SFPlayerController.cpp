// Fill out your copyright notice in the Description page of Project Settings.


#include "SFPlayerController.h"
#include "../Attribute/GeneralAttributeSet.h"

ASFPlayerController::ASFPlayerController(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	AttributeSet = CreateDefaultSubobject<UGeneralAttributeSet>(TEXT("AttributeSet"));
}

void ASFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Init();
	if (AttributeSet != nullptr) {
		AttributeSet->InitAttribute();
	}
	
	
}

