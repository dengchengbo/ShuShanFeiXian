// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "BaseStruct.generated.h"

/**
 * ¿ÉÍÏ×§Êý¾Ý
 */
USTRUCT(Blueprintable, BlueprintType)
struct GENERALMODULE_API FDraggableData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											ID = "N/A";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											Name = "N/A";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture*										Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											Type = "N/A";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int												Number = 0;
};


UENUM(BlueprintType)
enum class EGameMeshType : uint8
{
	SkeletalMesh = 0,
	StaticMesh
};


UCLASS()
class GENERALMODULE_API UBaseStruct : public UObject
{
	GENERATED_BODY()
	
};
