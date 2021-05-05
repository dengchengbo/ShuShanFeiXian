// Fill out your copyright notice in the Description page of Project Settings.


#include "RenderTarget2DActor.h"
#include "Components/SceneComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARenderTarget2DActor::ARenderTarget2DActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitComponent();

	

}

// Called when the game starts or when spawned
void ARenderTarget2DActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
bool is = false;
void ARenderTarget2DActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}


void ARenderTarget2DActor::InitComponent()
{

	MeshPlaceholder = CreateDefaultSubobject<USceneComponent>(TEXT("MeshPlaceholder"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(MeshPlaceholder);
	SpringArm->TargetArmLength = 300.0f;

	SceneCaptureComponent2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCaptureComponent2D"));
	SceneCaptureComponent2D->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}


bool ARenderTarget2DActor::UpdateRender_Implementation(AActor* _Target) { return false; }

