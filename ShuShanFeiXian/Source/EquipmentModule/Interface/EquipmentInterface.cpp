// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentInterface.h"
#include "../Component/EquipmentComponent.h"

// Add default functionality here for any IEquipmentInterface functions that are not pure virtual.


bool IEquipmentInterface::Equip_Implementation(UEquipmentComponent* _EquipmentComponent) { return false; }

bool IEquipmentInterface::TakeOff_Implementation(UEquipmentComponent* _EquipmentComponent) { return false; }
