//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.IO;
using System;

public class Devices : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public Devices(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Public/Devices.h";

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "ZED",
                "Stereolabs",
                "MixedReality"

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
                "HeadMountedDisplay"
            }
            );
    }
}


