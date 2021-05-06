// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneralAttributeSet.h"
#include "GameplayEffectExtension.h"

void UGeneralAttributeSet::InitAttribute()
{
	InitHealth(100);
	InitMaxHealth(100);

	Super::InitAttribute();
}

void UGeneralAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

	FString s1 = FString::SanitizeFloat(NewValue);
	GEngine->AddOnScreenDebugMessage
	(
		-1,
		10, 			//	显示的时间/秒
		FColor::Green, 	//	显示的颜色
		*s1			//	显示的信息
	);

	//ClampHealth(Attribute, NewValue, 0, MaxHealth.GetCurrentValue());

	/*FString s2 = FString::SanitizeFloat(NewValue);

	GEngine->AddOnScreenDebugMessage
	(
		-1,
		10, 			//	显示的时间/秒
		FColor::Blue, 	//	显示的颜色
		*s2				//	显示的信息
	);*/

	
}

void UGeneralAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	const FGameplayAttribute& Attribute = Data.EvaluatedData.Attribute;
	//Data.EvaluatedData.Attribute;

	/*FString s = FString::SanitizeFloat(Health.GetCurrentValue());
	GEngine->AddOnScreenDebugMessage
	(
		-1,
		10, 			//	显示的时间/秒
		FColor::Blue, 	//	显示的颜色
		*s				//	显示的信息
	);*/

	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		SetHealth(1.0f);
	};

	//ClampHealth(Data, 0, MaxHealth.GetCurrentValue());
}
