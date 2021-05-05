// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBPFunction.h"
#include "GameFramework\Character.h"
#include "Kismet/GameplayStatics.h"

void UBaseBPFunction::MouseClickActor(const UObject* WorldContext, ETraceTypeQuery TraceChannel, FHitResult& HitResult)
{
	UGameplayStatics::GetPlayerController(WorldContext, 0)->GetHitResultUnderCursorByChannel(TraceChannel, true, HitResult);
}


void UBaseBPFunction::FollowTheMouse(const UObject* WorldContext, ETraceTypeQuery TraceChannel, FVector SelfPos, FRotator& RotResult, FVector& MousePos)
{
	FHitResult res;
	
	MouseClickActor(WorldContext, TraceChannel, res);
	//UGameplayStatics::GetPlayerController(WorldContext, 0)->GetHitResultUnderCursorByChannel(TraceChannel, true, res);

	MousePos = res.Location;

	RotResult = UKismetMathLibrary::FindLookAtRotation(SelfPos, MousePos);
}

void UBaseBPFunction::AccordingToward(FVector _LookAt, ACharacter* _Charater, float& _MoveForward_3D, float& _MoveRight_3D)
{
	FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(_Charater->GetActorLocation(), _LookAt);

	FVector LookAtForward = UKismetMathLibrary::GetForwardVector(LookAtRot).GetSafeNormal();
	FVector LookAtRight = UKismetMathLibrary::GetRightVector(LookAtRot).GetSafeNormal();

	FVector Velocity = _Charater->GetVelocity().GetSafeNormal();

	float VelocityLength = (Velocity.Size() == 0.0f ? 1.0f : Velocity.Size());

	_MoveForward_3D = UKismetMathLibrary::Dot_VectorVector(Velocity, LookAtForward) / VelocityLength;
	_MoveRight_3D = UKismetMathLibrary::Dot_VectorVector(Velocity, LookAtRight) / VelocityLength;
}

