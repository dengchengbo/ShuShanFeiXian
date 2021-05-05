// Fill out your copyright notice in the Description page of Project Settings.


#include "SFConfigManager.h"

FComboList USFConfigManager::GetSFComboInfo(FString _ItemID)
{
	FComboList OutFormation;
	if (ComboInfoDataTable == nullptr)
	{
		return  OutFormation;
	}

	TArray<FName> Names = ComboInfoDataTable->GetRowNames();

	for (auto Name : Names)
	{
		OutFormation = *ComboInfoDataTable->FindRow<FComboList>(Name, "");
		if (OutFormation.ComboName == _ItemID) {
			return OutFormation;
		}
	}

	return OutFormation;
}