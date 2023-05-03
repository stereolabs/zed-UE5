//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class SpatialMappingEditor : ModuleRules
	{
        public SpatialMappingEditor(ReadOnlyTargetRules Target) : base(Target)
        {
            PrivatePCHHeaderFile = "Public/SpatialMappingEditorPlugin.h";

            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));
            bEnableUndefinedIdentifierWarnings = false;

            PrivateDependencyModuleNames.AddRange(new string[]
                {"Slate",
                    "SlateCore" });

            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "Stereolabs",
                     "SpatialMapping"
                }
                );

            PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
                    "Slate",
                    "SlateCore",
                    "Engine",
                    "UnrealEd",
                    "DesktopPlatform",
                    "InputCore"
                }
				);
		}
	}
}