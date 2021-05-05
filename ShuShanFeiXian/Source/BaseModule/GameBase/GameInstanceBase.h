// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/Public/Tickable.h"
#include "GameInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class BASEMODULE_API UGameInstanceBase : public UGameInstance, public FTickableGameObject
{
	GENERATED_BODY()
public:
	//interface for tickable gameobject
	virtual void Tick(float DeltaTime) override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;

	//
	virtual void Init() override;
	
};
