// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AbilityModule/Game/AbilityAIController.h"
#include "SFAIController.generated.h"

/**
 * 
 */
UCLASS()
//class SHUSHANFEIXIAN_API ASFAIController : public AAIController
class SHUSHANFEIXIAN_API ASFAIController : public AAbilityAIController
{
	GENERATED_BODY()

public:

	ASFAIController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Init();

public:

	UPROPERTY(BlueprintReadWrite)
	class UGeneralAttributeSet*				AttributeSet;
};
