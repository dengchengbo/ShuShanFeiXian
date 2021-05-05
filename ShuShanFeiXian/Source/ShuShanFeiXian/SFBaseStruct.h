// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "SFBaseStruct.generated.h"

/**
 * 
 */


UENUM(BlueprintType)
enum class EDragSource : uint8
{

	Inventory = 0,
	Equipment,
	SkillBook
};

UENUM(BlueprintType)
enum class ERenderMeshType : uint8
{	
	Temp = 0,
	Protagonist,
	Weapon
};

UENUM(BlueprintType)
enum class EAIAction : uint8
{
	Idle = 0,
	Fighting,
	TakeOff
};

USTRUCT(Blueprintable, BlueprintType)
struct SHUSHANFEIXIAN_API FComboInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage*							AnimMontage;

};

USTRUCT(Blueprintable, BlueprintType)
struct SHUSHANFEIXIAN_API FComboList : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString									ComboName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FComboInfo>						ComboList;

};


UCLASS()
class SHUSHANFEIXIAN_API USFBaseStruct : public UObject
{
	GENERATED_BODY()
	
};
