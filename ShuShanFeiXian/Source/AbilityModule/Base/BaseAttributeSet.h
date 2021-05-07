// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "BaseAttributeSet.generated.h"

/**
 * 
 */
// #include "GameplayEffectExtension.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


class FAttributeChangeDelegateEvent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChangeDelegateEvent, FString, AttributeName, float, AttributeValue);

UCLASS()
class ABILITYMODULE_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data, const FGameplayAttribute& Attribute);

public:

	UFUNCTION(BlueprintCallable, Category = "AttributeSet")
	virtual void InitAttribute();
	UFUNCTION(BlueprintImplementableEvent, Category = "AttributeSet", meta = (DisplayName = "InitAttribute", ScriptName = "InitAttribute"))
	void InitAttribute_Event();


public:

	UPROPERTY(BlueprintAssignable, Category = "DelegateEvent")
		FAttributeChangeDelegateEvent			AttributeChangeDelegate;

protected:

	void OnAttributeChange(FString AttributeName, float AttributeValue, bool IsSend = true);



};

#define CLAMPATTRIBUTE(PropertyName,Min,Max) \
{ \
	if (Data.EvaluatedData.Attribute == Get##PropertyName##Attribute())\
	{\
		Set##PropertyName(FMath::Clamp(Get##PropertyName(),(Min),(Max)));\
	};\
}


#define LISTENING_ATTRIBUTECHANGE(PropertyName)\
{\
	if (Attribute == Get##PropertyName##Attribute())\
	{\
		OnAttributeChange(""#PropertyName, Get##PropertyName());\
	};\
}