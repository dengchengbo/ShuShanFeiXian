// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Components/ActorComponent.h"
#include "GeneralModule/Base/BaseStruct.h"
#include "InventoryComponent.generated.h"



UENUM(BlueprintType)
enum class EInventoryAction : uint8
{

	AddItem = 0,
	RemoveItem,
	SwapItem
};

//�����Ʒ��Ϣ
USTRUCT(Blueprintable, BlueprintType)
struct INVENTORYMODULE_API FItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											ItemID = "N/A";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDraggableData									BaseData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool											CanStacking = false;		//�Ƿ�ɶѵ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											Discription = "N/A";		//����

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh*									Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject*										DataObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class APickUpActorBase>				PickUpActorBaseClass = nullptr;


};


//���±��� ί��
class FInventoryRefreshDelegateEvent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryRefreshDelegateEvent, EInventoryAction, Action);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class INVENTORYMODULE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;




public:

	void InitInventoryComponent();




	UFUNCTION(BlueprintPure, Category = "InventoryComponent")
	void GetInventory(TArray<FItemInfo>& _BackpackList) { _BackpackList = BackpackList; }

	UFUNCTION(BlueprintPure, Category = "InventoryComponent")
	AActor* GetOwnerActor() { return Owner; }

	UFUNCTION(BlueprintPure, Category = "InventoryComponent")
	APawn* GetOwnerPawn() { return Cast<APawn>(Owner); }

	 //���
	UFUNCTION(BlueprintCallable, Category = "InventoryComponent")
	void AddItem(FItemInfo _Info);

	//�Ƴ�
	UFUNCTION(BlueprintCallable, Category = "InventoryComponent")
	FItemInfo RemoveItem(int _Index,int _Num = 1);

	UFUNCTION(BlueprintCallable, Category = "InventoryComponent")
	void ThrowItem(int _Index, int _Num = 1);

	UFUNCTION(BlueprintImplementableEvent, Category = "InventoryComponent", meta = (DisplayName = "ThrowItem", ScriptName = "ThrowItem"))
	void ThrowItem_Event(FItemInfo _Info);

	//����
	UFUNCTION(BlueprintCallable, Category = "InventoryComponent")
	void SwapItem(int _Index_1, int _Index_2);

	//ʰȡ
	UFUNCTION(BlueprintCallable, Category = "InventoryComponent")
	void PickUpItem(class APickUpActorBase* _PickUpActor);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "InventoryComponent")
	void OpenInventory();


public:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryComponent")
	TArray<FItemInfo>	ItemList;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryComponent")
	int InventoryCapacity = 30;


	//���±��� ί��
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FInventoryRefreshDelegateEvent  OnInventoryRefresh;

private:

	AActor*				Owner = nullptr;


	//TArray<FDraggableData>		BackpackList;

	TArray<FItemInfo>			BackpackList;

	FItemInfo					TempInfo;


};
