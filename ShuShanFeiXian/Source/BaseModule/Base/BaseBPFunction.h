// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "BaseBPFunction.generated.h"


/*GEngine->AddOnScreenDebugMessage
(
	-1,
	10, 			//	显示的时间/秒
	FColor::Blue, 	//	显示的颜色
	"Hello! UE4"	//	显示的信息
);*/


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
