// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/PlayerController.h"
#include "AbilityModule/Game/AbilityPlayerController.h"
#include "SFPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHUSHANFEIXIAN_API ASFPlayerController : public AAbilityPlayerController /*public APlayerController*/
{
	GENERATED_BODY()

public:

	ASFPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Init();
	
public:

	UPROPERTY(BlueprintReadWrite)
	class UGeneralAttributeSet*					AttributeSet;
};
