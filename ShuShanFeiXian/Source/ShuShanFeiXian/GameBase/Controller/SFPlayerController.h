// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SFPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHUSHANFEIXIAN_API ASFPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Init();
	
};
