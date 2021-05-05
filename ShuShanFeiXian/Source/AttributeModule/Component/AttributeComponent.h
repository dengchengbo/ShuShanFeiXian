// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


USTRUCT()
struct ATTRIBUTEMODULE_API FAttributeBase
{	
	//GENERATED_BODY()
	GENERATED_USTRUCT_BODY()



};

/*USTRUCT(Blueprintable, BlueprintType)
struct ATTRIBUTEMODULE_API FAttributeThreshold : public FAttributeBase
{
	GENERATED_BODY()
	//GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float							MinValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float							CurValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float							MaxValue;

	FAttributeThreshold() :MinValue(0.0f),
						CurValue(0.0f),
						MaxValue(0.0f)
	{}


	virtual void Init() override;


	void sss() {};
};*/



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) , Blueprintable, BlueprintType)
class ATTRIBUTEMODULE_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
