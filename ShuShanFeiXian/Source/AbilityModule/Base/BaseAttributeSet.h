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


UCLASS()
class ABILITYMODULE_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

public:

	UFUNCTION(BlueprintCallable, Category = "AttributeSet")
	virtual void InitAttribute();
	UFUNCTION(BlueprintImplementableEvent, Category = "AttributeSet", meta = (DisplayName = "InitAttribute", ScriptName = "InitAttribute"))
	void InitAttribute_Event();

	UFUNCTION(BlueprintCallable, Category = "AttributeSet")
	UAbilitySystemComponent* Tempta() { return GetOwningAbilitySystemComponent(); };

protected:



};


#define CLAMPATTRIBUTE(PropertyName) \
	FORCEINLINE void Clamp##PropertyName(const FGameplayEffectModCallbackData& Data,float Min,float Max) \
{ \
	if (Data.EvaluatedData.Attribute == Get##PropertyName##Attribute())\
	{\
		Set##PropertyName(FMath::Clamp(Get##PropertyName(),Min,Max));\
	};\
}