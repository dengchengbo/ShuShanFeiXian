// Fill out your copyright notice in the Description page of Project Settings.


#include "SFCharacterBase.h"

// Sets default values
ASFCharacterBase::ASFCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASFCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	Init();
	
}

// Called every frame
void ASFCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASFCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ASFCharacterBase::Init()
{
	Init_Event();
}

void ASFCharacterBase::AttackStartNotify()
{
	IsAttack = true;
	AttackStartNotify_Event();
}

void ASFCharacterBase::AttackReplyNotify()
{
	IsAttackReply = true;
	AttackReplyNotify_Event();
}

void ASFCharacterBase::AttackEndNotify()
{
	IsAttack = false;
	IsAttackReply = false;
	AttackEndNotify_Event();
}

