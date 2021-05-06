// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AbilitySystemInterface.h"
#include "AbilityAIController.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYMODULE_API AAbilityAIController : public AAIController, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:

	AAbilityAIController(const FObjectInitializer& ObjectInitializer);

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbility")
	class UGameplayAbilityComponent*								AbilityComponent;

public:
	
};
