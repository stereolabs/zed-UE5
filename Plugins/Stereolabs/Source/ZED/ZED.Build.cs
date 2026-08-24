//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============
using UnrealBuildTool;
using System.IO;
using System;

public class ZED : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public string ProjectSavedConfigPathDirectory
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../../../Saved/Config/ZED/")); }
    }

    public string ProjectConfigPathDirectory
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../../../Config/")); }
    }


    public ZED(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Public/ZED.h";

#if UE_5_6_OR_LATER
        CppCompileWarningSettings.UndefinedIdentifierWarningLevel = WarningLevel.Error;
#elif UE_5_5_OR_LATER
        UndefinedIdentifierWarningLevel = WarningLevel.Error;
#else
        bEnableUndefinedIdentifierWarnings = true;
#endif

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                 "Stereolabs",
                 "Niagara",
                 "UMG",
                 "Slate",
                 "SlateCore",
                 "ProceduralMeshComponent",
                 "MeshDescription",
                 "CinematicCamera",
                 "LiveLinkInterface"

				// ... add other public dependencies that you statically link with here ...
			}
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",

                "Engine",

                "RenderCore",
                "InputCore",

                "RHI",
                "RHICore",
                "D3D11RHI"
            }
            );

        string ZedConfigFileName = "ZED.ini";
        string CameraConfigFileName = "Camera.ini";

        string ZedConfigFilePath = ProjectSavedConfigPathDirectory + ZedConfigFileName;
        string CameraConfigFilePath = ProjectSavedConfigPathDirectory + CameraConfigFileName;

        // Set default project settings (engine, input mappings used by the sample content, cook settings)
        if (!Directory.Exists(ProjectConfigPathDirectory))
        {
            Directory.CreateDirectory(ProjectConfigPathDirectory);
        }

        foreach (string ProjectConfigFileName in new string[] { "DefaultEngine.ini", "DefaultInput.ini", "DefaultGame.ini" })
        {
            string ProjectConfigFilePath = ProjectConfigPathDirectory + ProjectConfigFileName;
            if (!File.Exists(ProjectConfigFilePath))
            {
                File.Copy(Path.Combine(ModulePath, "Defaults", ProjectConfigFileName), ProjectConfigFilePath, true);
            }
        }

        // Set default SDK settings
        if (!Directory.Exists(ProjectSavedConfigPathDirectory))
        {
            Directory.CreateDirectory(ProjectSavedConfigPathDirectory);
        }

        // Copy files if they don't exist
        if (!File.Exists(ZedConfigFilePath))
        {
            File.Copy(Path.Combine(ModulePath, "Defaults", ZedConfigFileName), ZedConfigFilePath, true);
        }
        if (!File.Exists(CameraConfigFilePath))
        {
            File.Copy(Path.Combine(ModulePath, "Defaults", CameraConfigFileName), CameraConfigFilePath, true);
        }

        // Copy config file to shipped folder
        if (Target.Type != TargetRules.TargetType.Editor)
        {
            RuntimeDependencies.Add(ZedConfigFilePath, StagedFileType.NonUFS);
            RuntimeDependencies.Add(CameraConfigFilePath, StagedFileType.NonUFS);
        }

        // Calibration settings
        String MRFolderPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Stereolabs\\mr");

        // Create folder if it does not exist
        if (!Directory.Exists(MRFolderPath))
        {
            Directory.CreateDirectory(MRFolderPath);
        }

        // Create the path to the file and the macro for C++
        String CalibrationFilePathDefinition = "ZED_CALIBRAITON_FILE_PATH=" + "\"" + MRFolderPath + "\\Calibration.ini" + "\"";
        CalibrationFilePathDefinition = CalibrationFilePathDefinition.Replace("\\", "/");

        // Add the definition for C++
        PublicDefinitions.Add(CalibrationFilePathDefinition);

    }
}
