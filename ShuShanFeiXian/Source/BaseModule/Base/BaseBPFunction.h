// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "BaseBPFunction.generated.h"

/**
 * 
 */
UCLASS()
class BASEMODULE_API UBaseBPFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void MouseClickActor(const UObject* WorldContext, ETraceTypeQuery TraceChannel, FHitResult& HitResult);

	UFUNCTION(BlueprintCallable)
	static void FollowTheMouse(const UObject* WorldContext,ETraceTypeQuery TraceChannel, FVector SelfPos, FRotator& RotResult, FVector& MousePos);

	UFUNCTION(BlueprintCallable)
	static void AccordingToward(FVector _LookAt, ACharacter* _Charater,float& _MoveForward_3D, float& _MoveRight_3D);
	
};
