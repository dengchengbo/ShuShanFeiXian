// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityModule/Base/BaseAttributeSet.h"
#include "GeneralAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class SHUSHANFEIXIAN_API UGeneralAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData							Health;
	ATTRIBUTE_ACCESSORS(UGeneralAttributeSet, Health);
	
};
