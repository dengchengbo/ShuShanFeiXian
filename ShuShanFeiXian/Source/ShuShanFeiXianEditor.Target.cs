// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShuShanFeiXianEditorTarget : TargetRules
{
	public ShuShanFeiXianEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ShuShanFeiXian", "BaseModule", "AbilityModule", "GeneralModule", "InventoryModule", "EquipmentModule", "AttributeModule" } );
	}
}
