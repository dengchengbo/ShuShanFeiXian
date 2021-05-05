// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EquipmentData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class EQUIPMENTMODULE_API UEquipmentData : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "EquipmentData", meta = (ExposeOnSpawn = true, InstanceEditable = true))
	class UStreamableRenderAsset*		Mesh = nullptr;
	
};
