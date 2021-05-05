// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShuShanFeiXianTarget : TargetRules
{
	public ShuShanFeiXianTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ShuShanFeiXian", "BaseModule", "AbilityModule", "GeneralModule", "InventoryModule", "EquipmentModule", "AttributeModule" } );
	}
}
