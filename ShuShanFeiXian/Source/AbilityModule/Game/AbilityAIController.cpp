// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "AbilitySystemComponent.h"
#include "../Component/GameplayAbilityComponent.h"

AAbilityAIController::AAbilityAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	AbilityComponent = CreateDefaultSubobject<UGameplayAbilityComponent>(TEXT("AbilitySystemComponent"));

}

UAbilitySystemComponent* AAbilityAIController::GetAbilitySystemComponent() const
{
	return  Cast<UAbilitySystemComponent>(AbilityComponent);
}