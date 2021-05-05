// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../../SFBaseStruct.h"
#include "SFConfigManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SHUSHANFEIXIAN_API USFConfigManager : public UObject
{
	GENERATED_BODY()
	

	/**
	*����������Ϣ
	*/
	UFUNCTION(BlueprintCallable)
	FComboList GetSFComboInfo(FString _ItemID);
	UFUNCTION(BlueprintPure)
	FComboList GetSFComboInfo_Pure(FString _ItemID) { return GetSFComboInfo(_ItemID); };


protected:

	/**
	*������Ʒ��Ϣ��
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* ComboInfoDataTable = nullptr;
};
