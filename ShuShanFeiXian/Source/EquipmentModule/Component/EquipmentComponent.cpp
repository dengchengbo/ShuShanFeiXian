// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "../Object/EquipmentData.h"
#include "Components/MeshComponent.h"
#include "GeneralModule/Actor/RenderTarget2DActor.h"

// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void UEquipmentComponent::OpenEquipment()
{
	if (RenderTargetClass != nullptr) {
		FTransform Trans;
		Trans.SetLocation(FVector(4000000,0,0));
		FActorSpawnParameters Params;

		RenderTargetActor = Cast<ARenderTarget2DActor>(GetWorld()->SpawnActor(RenderTargetClass, &Trans, Params));
		RenderTargetActor->UpdateRender(GetOwner());
	}

	OpenEquipment_Event();
}


void UEquipmentComponent::CloseEquipment()
{
	if (RenderTargetActor != nullptr) {
		RenderTargetActor->Destroy();
	}

	CloseEquipment_Event();
}


void UEquipmentComponent::EquipWith(const FString& _Type, UEquipmentData* _Data)
{
	AddDataToMap(_Type,_Data);
	UpdateMesh(_Type);

	EquipWith_Event(_Type,_Data);
	OnEquipmentRefresh.Broadcast(EEquipmentAction::Equip);
	RenderTargetActor->UpdateRender(GetOwner());
}


void UEquipmentComponent::AttachMeshComponentToInfo(FString _Type, UMeshComponent* _MeshComponent, EGameMeshType _MeshType)
{
	FEquipmentInfo* info = EquipmentMap.Find(_Type);

	if (info == nullptr) { return; }

	info->MeshComponent = _MeshComponent;
	info->MeshType = _MeshType;
}

void UEquipmentComponent::AddDataToMap(const FString& _Type, UEquipmentData* _Data)
{
	FEquipmentInfo* info = EquipmentMap.Find(_Type);

	if (info == nullptr) { return; }

	info->Data = _Data;
}

void UEquipmentComponent::DeleteDataToMap(const FString& _Type)
{
	FEquipmentInfo* info = EquipmentMap.Find(_Type);

	if (info == nullptr) { return; }

	info->Data = nullptr;

}

void UEquipmentComponent::UpdateMesh(const FString& _Type, bool IsDelete)
{
	FEquipmentInfo* info = EquipmentMap.Find(_Type);

	if (info == nullptr||info->MeshComponent == nullptr|| info->Data == nullptr || info->Data->Mesh == nullptr) { return; }

	//Cast<USkeletalMeshComponent>(info->MeshComponent)->
		switch (info->MeshType) {
			case EGameMeshType::SkeletalMesh:

				if (IsDelete) {
					Cast<USkeletalMeshComponent>(info->MeshComponent)->SetSkeletalMesh(nullptr);
				}
				else {
					Cast<USkeletalMeshComponent>(info->MeshComponent)->SetSkeletalMesh(Cast<USkeletalMesh>(info->Data->Mesh));
				}
				
				break;
			case EGameMeshType::StaticMesh:

				if (IsDelete) {
					Cast<UStaticMeshComponent>(info->MeshComponent)->SetStaticMesh(nullptr);
				}
				else {
					Cast<UStaticMeshComponent>(info->MeshComponent)->SetStaticMesh(Cast<UStaticMesh>(info->Data->Mesh));
				}
				
				break;
			default:
				break;
		}

}

void UEquipmentComponent::TakeOffEquip(const FString& _Type)
{

	UpdateMesh(_Type, true);
	DeleteDataToMap(_Type);

	TakeOffEquip_Event(_Type);
	OnEquipmentRefresh.Broadcast(EEquipmentAction::TakeOff);
	RenderTargetActor->UpdateRender(GetOwner());
	
}
