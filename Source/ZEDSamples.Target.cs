//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.Collections.Generic;

public class ZEDSamplesTarget : TargetRules
{
	public ZEDSamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
        bOverrideBuildEnvironment = true;
        ExtraModuleNames.AddRange( new string[] { "ZEDSamples" } );
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        DefaultBuildSettings = BuildSettingsVersion.Latest;

        if (bBuildEditor)
		{
			ExtraModuleNames.AddRange(new string[] { "ZEDSamplesEditor" });
		}
	}
}
