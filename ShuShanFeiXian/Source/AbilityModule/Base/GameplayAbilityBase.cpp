// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbilityBase.h"
#include "../Component/GameplayAbilityComponent.h"



void UGameplayAbilityBase::InItData(FAbilityInfo* _Info)
{
	//ÉèÖÃÀäÈ´Ê±¼ä
	UGameplayEffect* GameplayEffect = GetCooldownGameplayEffect();

	if (GameplayEffect != nullptr) {

		float fCooldown = _Info->Cooldown;
		GameplayEffect->DurationMagnitude = FGameplayEffectModifierMagnitude(FScalableFloat(fCooldown));

	}
}

