// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Base/BaseStruct.h"
#include "DraggableObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GENERALMODULE_API UDraggableObject : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnTrigger", Meta = (ExposeOnSpawn = true, InstanceEditable = true))
		FDraggableData					Data;
};
