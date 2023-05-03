//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.IO;
using System;

public class SpatialMapping : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public SpatialMapping(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Public/SpatialMapping.h";
        bEnableUndefinedIdentifierWarnings = false;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                 "Stereolabs",
                 "ZED"

				// ... add other public dependencies that you statically link with here ...
			}
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "RenderCore",
                "Engine",
                "RHI"
            }
            );
    }
}


