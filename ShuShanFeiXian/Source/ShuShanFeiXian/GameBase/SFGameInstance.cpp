// Fill out your copyright notice in the Description page of Project Settings.


#include "SFGameInstance.h"
#include "../GameBase/Manager/SFConfigManager.h"



void USFGameInstance::Init()
{
	ConfigManager = NewObject<USFConfigManager>(this, ConfigManagerClass);

	Super::Init();
}

