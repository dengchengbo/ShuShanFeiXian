// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Components/ActorComponent.h"
#include "GeneralModule/Base/BaseStruct.h"
#include "EquipmentComponent.generated.h"


UENUM(BlueprintType)
enum class EEquipmentAction : uint8
{

	Equip = 0,
	TakeOff
};

//库存物品信息
USTRUCT(Blueprintable, BlueprintType)
struct EQUIPMENTMODULE_API FEquipmentInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMeshComponent*							MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EGameMeshType									MeshType = EGameMeshType::SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UEquipmentData*							Data;

};

//更新装备 委托
class FEquipmentRefreshDelegateEvent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEquipmentRefreshDelegateEvent, EEquipmentAction, Action);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class EQUIPMENTMODULE_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RenderTarget")
	class ARenderTarget2DActor*					RenderTargetActor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RenderTarget")
	TSubclassOf<class ARenderTarget2DActor>		RenderTargetClass = nullptr;


	//更新装备 委托
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FEquipmentRefreshDelegateEvent				OnEquipmentRefresh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EquipmentComponent")
	TMap<FString, FEquipmentInfo>			EquipmentMap;

public:

	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void OpenEquipment();
	UFUNCTION(BlueprintImplementableEvent, Category = "EquipmentComponent", meta = (DisplayName = "OpenEquipment", ScriptName = "OpenEquipment"))
	void OpenEquipment_Event();

	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void CloseEquipment();
	UFUNCTION(BlueprintImplementableEvent, Category = "EquipmentComponent", meta = (DisplayName = "CloseEquipment", ScriptName = "CloseEquipment"))
	void CloseEquipment_Event();

	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void AttachMeshComponentToInfo(FString _Type, class UMeshComponent* _MeshComponent, EGameMeshType _MeshType);

	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void AddDataToMap(const FString& _Type, class UEquipmentData* _Data);

	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void DeleteDataToMap(const FString& _Type);


	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void EquipWith(const FString& _Type, class UEquipmentData* _Data);
	UFUNCTION(BlueprintImplementableEvent, Category = "EquipmentComponent", meta = (DisplayName = "EquipWith", ScriptName = "EquipWith"))
	void EquipWith_Event(const FString& _Type, class UEquipmentData* _Data);


	UFUNCTION(BlueprintCallable, Category = "EquipmentComponent")
	void TakeOffEquip(const FString& _Type);
	UFUNCTION(BlueprintImplementableEvent, Category = "EquipmentComponent", meta = (DisplayName = "TakeOffEquip", ScriptName = "TakeOffEquip"))
	void TakeOffEquip_Event(const FString& _Type);




public:

	void UpdateMesh(const FString& _Type, bool IsDelete = false);
};
