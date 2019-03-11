// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class mavlink_c : ModuleRules
{
	public mavlink_c(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",

			}
            );
        PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "include")
			}
			);
						
		
	}
}
