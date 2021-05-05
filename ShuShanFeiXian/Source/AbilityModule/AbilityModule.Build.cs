// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AbilityModule : ModuleRules
{
	public AbilityModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayAbilities", "GameplayTags", "GameplayTasks", "GeneralModule"});
	}
}
