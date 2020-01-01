// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class LDBPluginSnappy : ModuleRules
{
	public LDBPluginSnappy(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add("snappy.lib");
		}
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PublicAdditionalLibraries.Add("snappy");
            //PublicDelayLoadDLLs.Add("libsnappy.so.1.1.7");
        }
    }
}
