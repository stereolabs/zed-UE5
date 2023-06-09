//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.IO;
using System;

public class Stereolabs : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    public string ProjectBinariesPathDirectory
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../../Binaries/Win64/")); }
    }


    public Stereolabs(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Public/Stereolabs.h";

        bEnableUndefinedIdentifierWarnings = false;

        string CudaSDKPath = System.Environment.GetEnvironmentVariable("CUDA_PATH", EnvironmentVariableTarget.Machine);
        string ZEDSDKPath = System.Environment.GetEnvironmentVariable("ZED_SDK_ROOT_DIR", EnvironmentVariableTarget.Machine);

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "MixedReality"

				// ... add other public dependencies that you statically link with here ...
			}
            );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "RenderCore",
                "RHI",
                "RHICore",
                "UMG",
                "SlateCore"
            }
            );

        // Paths for low-level directx and opengl access
        string engine_path = Path.GetFullPath(Target.RelativeEnginePath);

        PrivateIncludePaths.AddRange(
          new string[]
          {
                engine_path + "Source/Runtime/Windows/D3D11RHI/Private/",
                engine_path + "Source/Runtime/Windows/D3D11RHI/Private/Windows",
                engine_path + "Source/Runtime/D3D12RHI/Private/Windows",
                engine_path + "Source/Runtime/D3D12RHI/Private/"
              // ... add other private include paths required here ...
          }
          );

        // required by D3D11RHI
        AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAPI");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "AMD_AGS");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAftermath");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "IntelMetricsDiscovery");
        AddEngineThirdPartyPrivateStaticDependencies(Target, "IntelExtensionsFramework");

        PrivateDependencyModuleNames.AddRange(new string[] {
                        "D3D11RHI",
                        "D3D12RHI",
                    });

        AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11", "DX12");


        string cApiPath = Path.Combine(ModulePath, "../ThirdParty/sl_zed_c/");
        LoadZEDSDK(Target, ZEDSDKPath);
        LoadCUDA(Target, CudaSDKPath);
        LoadCWrapper(Target, cApiPath);
    }

    public void LoadZEDSDK(ReadOnlyTargetRules Target, string DirPath)
    {
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            if(!Directory.Exists(DirPath))
            {
                string Err = string.Format("ZED SDK missing");
                System.Console.WriteLine(Err);
                throw new BuildException(Err);
            }

            // Check SDK version
            string DefinesHeaderFilePath = Path.Combine(DirPath, "include\\sl\\Camera.hpp");
            string Major = "4";
            string Minor = "0";

            // Find SDK major and minor version and compare
            foreach (var line in File.ReadLines(DefinesHeaderFilePath))
            {
                if (!string.IsNullOrEmpty(line))
                {
                    if(line.Contains("#define ZED_SDK_MAJOR_VERSION"))
                    {
                        string SDKMajor = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)[2];
                        if(!SDKMajor.Equals(Major))
                        {
                            string Err = string.Format("ZED SDK Major Version mismatch : found {0} expected {1}", SDKMajor, Major);
                            System.Console.WriteLine(Err);
                            throw new BuildException(Err);
                        }
                    }
                    else if (line.Contains("#define ZED_SDK_MINOR_VERSION"))
                    {
                        string SDKMinor = line.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)[2];
                        if (!SDKMinor.Equals(Minor))
                        {
                            string Err = string.Format("ZED SDK Minor Version mismatch : found {0} expected {1}", SDKMinor, Minor);
                            System.Console.WriteLine(Err);
                            throw new BuildException(Err);
                        }

                        break;
                    }
                }
            }

            // Set the paths to the SDK
            //string[] LibrariesNames = Directory.GetFiles(Path.Combine(DirPath, "lib"));

            PublicIncludePaths.Add(Path.Combine(DirPath, "include"));
            //PublicLibraryPaths.Add(Path.Combine(DirPath, "lib"));

            PublicAdditionalLibraries.Add(Path.Combine(DirPath, "lib", "sl_zed64.lib"));
        }
    }

    public void LoadCUDA(ReadOnlyTargetRules Target, string DirPath)
    {
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            if (!Directory.Exists(DirPath))
            {
                string Err = string.Format("CUDA SDK missing");
                System.Console.WriteLine(Err);
                throw new BuildException(Err);
            }

            string[] LibrariesName =  {
                                        "cuda",
                                        "cudart"
                                      };

            PublicIncludePaths.Add(Path.Combine(DirPath, "include"));

            foreach (string Library in LibrariesName)
            {
                PublicAdditionalLibraries.Add(Path.Combine(DirPath, "lib\\x64", Library + ".lib"));
            }
        }
    }

    public void LoadCWrapper(ReadOnlyTargetRules Target, string DirPath)
    {
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            if (!Directory.Exists(DirPath))
            {
                string Err = string.Format("Wrapper missing");
                System.Console.WriteLine(Err);
                throw new BuildException(Err);
            }

            string DLLName = "sl_zed_c.dll";
            string LibName = "sl_zed_c.lib";
            PublicAdditionalLibraries.Add(Path.Combine(DirPath, "lib", LibName));
            PublicDelayLoadDLLs.Add(DLLName);

            string DLLPath = Path.Combine(ModulePath, "../ThirdParty/sl_zed_c/bin/", DLLName);

            PublicIncludePaths.Add(Path.Combine(DirPath, "include"));

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
