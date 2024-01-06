// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Protobuf : ModuleRules
{
	public Protobuf(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicSystemLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

		PublicSystemLibraries.Add("libprotobuf.lib");
		PublicSystemLibraries.Add("libprotoc.lib");
	}
}
