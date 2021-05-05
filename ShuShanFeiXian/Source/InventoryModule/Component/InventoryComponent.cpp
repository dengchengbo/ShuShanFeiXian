// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "../Actor/PickUpActorBase.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	InitInventoryComponent();
	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}


void UInventoryComponent::InitInventoryComponent()
{
	//FItemInfo Info;
	BackpackList.Init(TempInfo, InventoryCapacity);

	Owner = GetOwner();
}


void UInventoryComponent::AddItem(FItemInfo _Info)
{

	int first = -1;
	
		for (int i = 0; i < InventoryCapacity; ++i) {
			FItemInfo temp = BackpackList[i];

			if (_Info.CanStacking && temp.ItemID == _Info.ItemID) {
				temp.BaseData.Number += _Info.BaseData.Number;
				BackpackList[i] = temp;
				OnInventoryRefresh.Broadcast(EInventoryAction::AddItem);
				return;
			}

			if (first == -1 && temp.ItemID == "N/A") {
				first = i;
			}

		}



		if (first != -1) {
			BackpackList[first] = _Info;
			OnInventoryRefresh.Broadcast(EInventoryAction::AddItem);
		}
	
	
}

FItemInfo UInventoryComponent::RemoveItem(int _Index, int _Num)
{
	FItemInfo throwItem = BackpackList[_Index];
	FItemInfo *item = &BackpackList[_Index];

	if (_Num <= 0 || item->ItemID == "N/A")
	{
		////FItemInfo temp;
		return TempInfo;
	}

	if (item->BaseData.Number > _Num) {
		item->BaseData.Number -= _Num;
		throwItem.BaseData.Number = _Num;
	}
	else
	{
		//FItemInfo temp;
		BackpackList[_Index] = TempInfo;
	}


	OnInventoryRefresh.Broadcast(EInventoryAction::RemoveItem);
	return throwItem;
}


void UInventoryComponent::ThrowItem(int _Index, int _Num)
{
	FItemInfo throwItem = RemoveItem(_Index, _Num);
	ThrowItem_Event(throwItem);
}



void UInventoryComponent::SwapItem(int _Index_1, int _Index_2)
{
	if (_Index_1 < 0 || _Index_1 >= InventoryCapacity|| _Index_2 < 0 || _Index_2 >= InventoryCapacity) { return; }

	BackpackList.Swap(_Index_1, _Index_2);
	OnInventoryRefresh.Broadcast(EInventoryAction::SwapItem);
}

void UInventoryComponent::PickUpItem(APickUpActorBase* _PickUpActor)
{
	
	AddItem(_PickUpActor->ItemInfo);

	_PickUpActor->BePickedUp();
}