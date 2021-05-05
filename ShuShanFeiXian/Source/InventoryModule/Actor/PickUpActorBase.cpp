// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpActorBase.h"

// Sets default values
APickUpActorBase::APickUpActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	//StaticMesh = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	StaticMesh->SetupAttachment(RootComponent);

	
}

// Called when the game starts or when spawned
void APickUpActorBase::BeginPlay()
{
	Super::BeginPlay();
	
	//StaticMesh->
	/*if (ItemInfo.Mesh != nullptr) {
		StaticMesh->SetStaticMesh(ItemInfo.Mesh);
		////StaticMesh->SetSimulatePhysics(true);
	}*/
}

// Called every frame
void APickUpActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APickUpActorBase::BePickedUp()
{
	Destroy();
}

void APickUpActorBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FProperty* PropertyThatChanged = PropertyChangedEvent.Property;

	if (PropertyThatChanged != nullptr)
	{


		if (PropertyThatChanged->GetFName() == GET_MEMBER_NAME_CHECKED(FItemInfo, Mesh)) {

			if (StaticMesh != nullptr && ItemInfo.Mesh != nullptr && StaticMesh->GetStaticMesh() != ItemInfo.Mesh){

				StaticMesh->SetStaticMesh(ItemInfo.Mesh);

			}
		}
	}
}

void APickUpActorBase::SetData(UObject* _Data)
{
	ItemInfo.DataObject = _Data;
}