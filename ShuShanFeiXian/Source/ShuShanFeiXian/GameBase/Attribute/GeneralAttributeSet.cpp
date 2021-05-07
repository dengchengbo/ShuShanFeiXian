// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneralAttributeSet.h"
#include "GameplayEffectExtension.h"

void UGeneralAttributeSet::InitAttribute()
{
	InitHealth(100);
	InitMaxHealth(100);

	Super::InitAttribute();
}

void UGeneralAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

}

void UGeneralAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data, const FGameplayAttribute& Attribute)
{
	Super::PostGameplayEffectExecute(Data, Attribute);

	CLAMPATTRIBUTE(Health, 0.0f, MaxHealth.GetCurrentValue());

	LISTENING_ATTRIBUTECHANGE(Health);
}
