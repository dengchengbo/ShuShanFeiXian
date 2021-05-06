// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GeneralModule/Base/BaseStruct.h"
#include "GameplayAbilityComponent.generated.h"


USTRUCT(Blueprintable, BlueprintType)
struct ABILITYMODULE_API FAbilityInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString											AbilityID = "N/A";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDraggableData									BaseData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UGameplayAbilityBase>			AbilityClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool											AddSkillBook = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float											Cooldown = 0.001f;

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
//class ABILITYMODULE_API UGameplayAbilityComponent : public UActorComponent, public IAbilitySystemInterface
class ABILITYMODULE_API UGameplayAbilityComponent : public UAbilitySystemComponent, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameplayAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
private:

	bool GiveAbility_A(const UObject* WorldContext, const FString& _AbilityID);

	bool GiveAbility_B(TPair<FString, FAbilityInfo> _AbilityPair);


	bool RemoveAbility_A(const FString& _AbilityID);



public:

	/**
	*�Ƿ��ʼ��
	*/
	UFUNCTION(BlueprintCallable)
	bool IsInit() { return bIsInit; }

	/**
	*��ʼ��
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool Init(AActor* InOwnerActor, AActor* InAvatarActor);
	virtual bool Init_Implementation(AActor* InOwnerActor, AActor* InAvatarActor);

	/**
	*�������
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool GiveAbility(const UObject* WorldContext, const FString& _AbilityID);
	virtual bool GiveAbility_Implementation(const UObject* WorldContext, const FString& _AbilityID);

	/**
	*�Ƴ�����
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool RemoveAbility(const FString& _AbilityID);
	virtual bool RemoveAbility_Implementation(const FString& _AbilityID);

	/**
	*�ͷ�����
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool TryActivateAbilityByID(const FString& _AbilityID);
	virtual bool TryActivateAbilityByID_Implementation(const FString& _AbilityID);

	/**
	*��ȡ������Ϣ
	*/
	FAbilityInfo* GetAbilityInfo(const FString& _AbilityID);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAbilityInfo", ScriptName = "GetAbilityInfo"))
	void GetAbilityInfo_Blueprint(const FString& _AbilityID, FAbilityInfo& __AbilityInfo);

	/*
	*��ȡ��������
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetAbilityObject", ScriptName = "GetAbilityObject"))
	class UGameplayAbilityBase* GetAbilityObject(const FString& _AbilityID);

	UFUNCTION(BlueprintCallable, Meta = (Tooltip = "This function can be used to trigger an ability on the actor in question with useful payload data."))
	bool SendGameplayEvent(FGameplayTag EventTag, FGameplayEventData Payload);


public:

	UPROPERTY(BlueprintReadOnly, Category = "GameplayAbility")
		class UAbilitySystemComponent*				AbilitySystemComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbility")
		TArray<FString>								AbilitiesArray;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayAbility")
		bool										bCanAbility = true;

	//�������ݱ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameplayAbility")
		UDataTable*									AbilityInfoDataTable = nullptr;


	UPROPERTY(BlueprintReadWrite, Category = "GameplayAbility")
		TMap<FString, FAbilityInfo>					SkillBookMap;



private:

	TMap<FString, FGameplayAbilitySpecHandle>	AbilitiesHandleMap;

	bool bIsInit = false;
};
