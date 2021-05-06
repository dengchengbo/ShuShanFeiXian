// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityPlayerController.h"
#include "AbilitySystemComponent.h"
#include "../Component/GameplayAbilityComponent.h"



AAbilityPlayerController::AAbilityPlayerController(const FObjectInitializer& ObjectInitializer) :Super(FObjectInitializer::Get())
{
	AbilityComponent = CreateDefaultSubobject<UGameplayAbilityComponent>(TEXT("AbilitySystemComponent"));

}

UAbilitySystemComponent* AAbilityPlayerController::GetAbilitySystemComponent() const
{
	return  Cast<UAbilitySystemComponent>(AbilityComponent);
}


