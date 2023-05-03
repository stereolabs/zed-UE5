//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class ZEDEditor : ModuleRules
	{
        public ZEDEditor(ReadOnlyTargetRules Target) : base(Target)
        {
            PrivatePCHHeaderFile = "Public/ZEDEditorPlugin.h";

            bEnableUndefinedIdentifierWarnings = false;


            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
            PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

            PrivateDependencyModuleNames.AddRange(new string[]
                {"Slate",
                    "SlateCore" });

            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "Stereolabs",
                     "ZED"
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
                    "InputCore",
                    "AnimGraph",
                    "BlueprintGraph",
		             "AnimGraphRuntime"
                }
				);
		}
	}
}