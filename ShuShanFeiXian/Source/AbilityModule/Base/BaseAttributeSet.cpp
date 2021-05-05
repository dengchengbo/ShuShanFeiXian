// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"


void UBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	SetHealth(1);
}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{

}

