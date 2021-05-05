// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../BaseModule/GameBase/GameInstanceBase.h"
#include "SFGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHUSHANFEIXIAN_API USFGameInstance : public UGameInstanceBase
{
	GENERATED_BODY()

public:

	virtual void Init() override;

public:

	/**
	配置管理器
	*/
	UPROPERTY(BlueprintReadOnly)
	class USFConfigManager*					ConfigManager = nullptr;

protected:

	/**
	配置管理类
	*/
	UPROPERTY(EditAnywhere)
	TSubclassOf<class USFConfigManager>		ConfigManagerClass = nullptr;
};
