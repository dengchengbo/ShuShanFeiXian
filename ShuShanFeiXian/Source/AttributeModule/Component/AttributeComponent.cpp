// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeComponent.h"
#include "Kismet2/StructureEditorUtils.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	//FEdGraphSchema::

	//UEdGraphSchema_K2::PC_Exec;
	//FEdGraphPinType();
	//FStructureEditorUtils::AddedVariable();
}


void  UAttributeComponent::TempSSS()
{
	
	//FStructureEditorUtils::AddVariable(Struct, FEdGraphPinType(FName("int"),NAME_None,nullptr, EPinContainerType::None,false,FEdGraphTerminalType()));
}
