// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RenderTarget2DActor.generated.h"

UCLASS()
class GENERALMODULE_API ARenderTarget2DActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARenderTarget2DActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool UpdateRender(AActor* _Target);
	virtual bool UpdateRender_Implementation(AActor* _Target);

protected:

	void InitComponent();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USceneComponent*									MeshPlaceholder = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent*								SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USceneCaptureComponent2D*							SceneCaptureComponent2D = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RenderTarget")
		TMap<FName,class USkeletalMesh*>						SkeletalMeshMap;


private:

		TMap<FName, class USkeletalMeshComponent*>				SkeletalMeshComponentMap;

};
