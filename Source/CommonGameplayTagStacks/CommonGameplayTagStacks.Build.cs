// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CommonGameplayTagStacks : ModuleRules
{
	public CommonGameplayTagStacks(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new[]
		{ 
			"Core",
			"NetCore",
			"CoreUObject",
			"GameplayTags",
		});
			
		
		PrivateDependencyModuleNames.AddRange(new[] 
		{
			"CoreUObject",
			"Engine",
		});
	}
}
