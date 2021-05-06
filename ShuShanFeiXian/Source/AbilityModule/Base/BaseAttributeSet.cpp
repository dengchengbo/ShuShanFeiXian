// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"




void UBaseAttributeSet::InitAttribute()
{
	InitAttribute_Event();
}

void UBaseAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	
}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{

}

