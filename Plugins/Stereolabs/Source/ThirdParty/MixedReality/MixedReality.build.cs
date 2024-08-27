//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using System;
using System.IO;
using UnrealBuildTool;

public class MixedReality : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public string ProjectBinariesPathDirectory
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../../Binaries/Win64/")); }
    }

    public MixedReality(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;
        
        PublicDependencyModuleNames.AddRange(new string[] { "Eigen" });

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string PostFix = "64";
            string[] LibrariesName =  {
                                        "sl_mr_core"
                                      };

            PublicIncludePaths.Add(ModulePath + "/include");
            //PublicLibraryPaths.Add(ModulePath + "/lib");

            foreach (string Library in LibrariesName)
            {
                string DLLName = Library + PostFix + ".dll";
                string LibName = Library + PostFix + ".lib";

                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "lib", LibName));
                PublicDelayLoadDLLs.Add(DLLName);

                string DLLPath = Path.Combine(ModulePath + "/bin/", DLLName);

                if (Target.Type != TargetRules.TargetType.Editor)
                {
                    if (!Directory.Exists(ProjectBinariesPathDirectory))
                    {
                        Directory.CreateDirectory(ProjectBinariesPathDirectory);
                    }

                    // Copy to the project binary folder
                    File.Copy(DLLPath, Path.Combine(ProjectBinariesPathDirectory, DLLName), true);

                    // Add library to the packaged binary folder
                    RuntimeDependencies.Add(ProjectBinariesPathDirectory + DLLName, StagedFileType.NonUFS);
                }
                // Remove the library if it already exist in the binary folder
                else
                {
                    if (Directory.Exists(ProjectBinariesPathDirectory) && File.Exists(Path.Combine(ProjectBinariesPathDirectory, DLLName)))
                    {
                        File.Delete(Path.Combine(ProjectBinariesPathDirectory, DLLName));
                    }

                    if (!Directory.Exists(ProjectBinariesPathDirectory))
                    {
                        Directory.CreateDirectory(ProjectBinariesPathDirectory);
                    }

                    // Copy to the project binary folder
                    File.Copy(DLLPath, Path.Combine(ProjectBinariesPathDirectory, DLLName), true);

                    // Add library to the packaged binary folder
                    RuntimeDependencies.Add(ProjectBinariesPathDirectory + DLLName, StagedFileType.NonUFS);
                }
            }
        }
    }
}
