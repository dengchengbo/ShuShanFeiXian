// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseModule/Base/BaseBPFunction.h"
#include "SFBPFunction.generated.h"

/**
 * 
 */
UCLASS()
class SHUSHANFEIXIAN_API USFBPFunction : public UBaseBPFunction
{
	GENERATED_BODY()
public:
		//��ȡ��Ϸʵ��
	UFUNCTION(BlueprintCallable)
		static class USFGameInstance* GetSFGameInstance(const UObject* WorldContext);
	UFUNCTION(BlueprintPure)
		static class USFGameInstance* GetSFGameInstance_Pure(const UObject* WorldContext) { return GetSFGameInstance(WorldContext); };

	//��ȡ��Ϸģʽ
	UFUNCTION(BlueprintCallable)
		static class ASFGameMode* GetSFGameMode(const UObject* WorldContext);
	UFUNCTION(BlueprintPure)
		static class ASFGameMode* GetSFGameMode_Pure(const UObject* WorldContext) { return GetSFGameMode(WorldContext); };

	//��ȡ��ɫ
	UFUNCTION(BlueprintCallable)
		static class ASFCharacterBase* GetSFPlayerCharacter(const UObject* WorldContext, int32 Num = 0);
	UFUNCTION(BlueprintPure)
		static class ASFCharacterBase* GetSFPlayerCharacter_Pure(const UObject* WorldContext, int32 Num = 0) { return GetSFPlayerCharacter(WorldContext, Num); };


	//��ȡ��ɫ
	UFUNCTION(BlueprintCallable)
		static class USFConfigManager* GetSFConfigManager(const UObject* WorldContext);
	UFUNCTION(BlueprintPure)
		static class USFConfigManager* GetSFConfigManager_Pure(const UObject* WorldContext) { return GetSFConfigManager(WorldContext); };
	
};
