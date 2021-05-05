// Fill out your copyright notice in the Description page of Project Settings.


#include "SFBPFunction.h"
#include "Kismet/GameplayStatics.h"
#include "./GameBase/SFGameInstance.h"
#include "./GameBase/SFGameMode.h"
#include "GameBase/Manager/SFConfigManager.h"
#include "./GameBase/Character/SFCharacterBase.h"


USFGameInstance* USFBPFunction::GetSFGameInstance(const UObject* WorldContext)
{
	UGameInstance* Instance = UGameplayStatics::GetGameInstance(WorldContext);
	return Cast<USFGameInstance>(Instance);
}

ASFGameMode* USFBPFunction::GetSFGameMode(const UObject* WorldContext)
{
	return Cast<ASFGameMode>(UGameplayStatics::GetGameMode(WorldContext));
}

ASFCharacterBase* USFBPFunction::GetSFPlayerCharacter(const UObject* WorldContext, int32 Num)
{ 
	return Cast<ASFCharacterBase>(UGameplayStatics::GetPlayerPawn(WorldContext, Num));
}

USFConfigManager* USFBPFunction::GetSFConfigManager(const UObject* WorldContext)
{
	auto GameInst = GetSFGameInstance(WorldContext);
	if (GameInst == nullptr) {
		return nullptr;
	}
	return GameInst->ConfigManager;
}



