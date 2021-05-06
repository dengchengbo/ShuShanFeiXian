// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AbilitySystemInterface.h"
#include "AbilityPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ABILITYMODULE_API AAbilityPlayerController : public APlayerController, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAbilityPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "GameplayAbility")
	class UGameplayAbilityComponent*			AbilityComponent;

public:

	
};
