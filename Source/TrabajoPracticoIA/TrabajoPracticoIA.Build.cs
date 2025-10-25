// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TrabajoPracticoIA : ModuleRules
{
	public TrabajoPracticoIA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
