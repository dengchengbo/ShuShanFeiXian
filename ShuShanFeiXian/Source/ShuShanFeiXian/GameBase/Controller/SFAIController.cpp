// Fill out your copyright notice in the Description page of Project Settings.


#include "SFAIController.h"
#include "../Attribute/GeneralAttributeSet.h"


ASFAIController::ASFAIController(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	AttributeSet = CreateDefaultSubobject<UGeneralAttributeSet>(TEXT("AttributeSet"));
}


void ASFAIController::BeginPlay()
{
	Super::BeginPlay();

	Init();
	if (AttributeSet != nullptr) {
		AttributeSet->InitAttribute();
	}


}

