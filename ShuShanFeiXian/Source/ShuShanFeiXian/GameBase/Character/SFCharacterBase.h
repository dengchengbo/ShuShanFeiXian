// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SFCharacterBase.generated.h"

UCLASS()
class SHUSHANFEIXIAN_API ASFCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASFCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/*--- ÆÕÍ¨¹¥»÷ ---*/

	/*
	* ¹¥»÷¿ªÊ¼
	*/
	UFUNCTION(BlueprintCallable, Category = "SFCharacterBase")
	void AttackStartNotify();
	UFUNCTION(BlueprintImplementableEvent, Category = "SFCharacterBase", meta = (DisplayName = "AttackStartNotify", ScriptName = "AttackStartNotify"))
	void AttackStartNotify_Event();

	/*
	* ¹¥»÷»Ø¸´
	*/
	UFUNCTION(BlueprintCallable, Category = "SFCharacterBase")
	void AttackReplyNotify();
	UFUNCTION(BlueprintImplementableEvent, Category = "SFCharacterBase", meta = (DisplayName = "AttackReplyNotify", ScriptName = "AttackReplyNotify"))
	void AttackReplyNotify_Event();

	/*
	* ¹¥»÷½áÊø
	*/
	UFUNCTION(BlueprintCallable, Category = "SFCharacterBase")
	void AttackEndNotify();
	UFUNCTION(BlueprintImplementableEvent, Category = "SFCharacterBase", meta = (DisplayName = "AttackEndNotify", ScriptName = "AttackEndNotify"))
	void AttackEndNotify_Event();
	

protected:

	/*
	* ³õÊ¼»¯
	*/
	UFUNCTION(BlueprintCallable, Category = "SFCharacterBase")
	void Init();
	UFUNCTION(BlueprintImplementableEvent, Category = "SFCharacterBase", meta = (DisplayName = "Init", ScriptName = "Init"))
	void Init_Event();

public:

	/*--- ÒÆ¶¯ ---*/

	UPROPERTY(BlueprintReadWrite)
	float		MoveUp = 0.0f;

	UPROPERTY(BlueprintReadWrite)
	float		MoveRight = 0.0f;


	/*--- ÆÕÍ¨¹¥»÷ ---*/

	UPROPERTY(BlueprintReadWrite)
	bool		IsAttack = false;

	UPROPERTY(BlueprintReadWrite)
	bool		IsAttackReply = false;

};
