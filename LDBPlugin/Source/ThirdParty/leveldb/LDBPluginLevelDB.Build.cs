// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class LDBPluginLevelDB : ModuleRules
{
	public LDBPluginLevelDB(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add("leveldb.lib");
		}
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            PublicAdditionalLibraries.Add("leveldb");
           // PublicDelayLoadDLLs.Add("libleveldb.so.1.22.0");
        }
	}
}
