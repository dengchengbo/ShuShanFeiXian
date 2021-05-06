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
	CLAMPATTRIBUTE(Health);
	

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData							MaxHealth;
	ATTRIBUTE_ACCESSORS(UGeneralAttributeSet, MaxHealth);

public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	virtual void InitAttribute() override;

};
