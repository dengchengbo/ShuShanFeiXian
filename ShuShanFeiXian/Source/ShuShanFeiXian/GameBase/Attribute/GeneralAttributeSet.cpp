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


}

void UGeneralAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	const FGameplayAttribute& Attribute = Data.EvaluatedData.Attribute;


	ClampHealth(Data, 0, MaxHealth.GetCurrentValue());
}
