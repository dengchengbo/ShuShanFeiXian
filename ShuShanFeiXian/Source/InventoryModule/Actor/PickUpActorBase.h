// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Component/InventoryComponent.h"
#include "PickUpActorBase.generated.h"

UCLASS()
class INVENTORYMODULE_API APickUpActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

public:

	UFUNCTION(BlueprintCallable, Category = "SpawnTrigger")
	void SetData(UObject* _Data);

public:

	void BePickedUp();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnTrigger", Meta = (ExposeOnSpawn = true, InstanceEditable = true))
	FItemInfo					ItemInfo;

private:

	UPROPERTY(Category = AActor, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent*		StaticMesh = nullptr;

};
