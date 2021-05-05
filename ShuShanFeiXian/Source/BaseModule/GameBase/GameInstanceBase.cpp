// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstanceBase.h"


void UGameInstanceBase::Tick(float DeltaTime)
{

}

bool UGameInstanceBase::IsTickable() const
{
	return GWorld->HasBegunPlay();
}

TStatId UGameInstanceBase::GetStatId() const
{
	return TStatId();
}

void UGameInstanceBase::Init()
{
	Super::Init();
}

