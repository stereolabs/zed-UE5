//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.Collections.Generic;

public class ZEDSamplesTarget : TargetRules
{
    public ZEDSamplesTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        bOverrideBuildEnvironment = true;
        ExtraModuleNames.AddRange(new string[] { "ZEDSamples" });
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        DefaultBuildSettings = BuildSettingsVersion.Latest;

        // Fixes compilation error with ue5.6.
        GlobalDefinitions.Add("UE_ENABLE_INCLUDE_ORDER_DEPRECATED_IN_5_7=0");

        if (bBuildEditor)
        {
            ExtraModuleNames.AddRange(new string[] { "ZEDSamplesEditor" });
        }
    }
}
