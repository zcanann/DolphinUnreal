// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using System.Linq;
using UnrealBuildTool;

public class DolphinUnreal : ModuleRules
{
	public DolphinUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		LoadLibrary(
			Target,
			new string[]
			{
				"ThirdParty/dolphin-api/include/",
			},
			"Binaries/ThirdParty/DolphinAPI/Win64/DolphinAPI.lib"
		);


		PublicIncludePaths.AddRange(
			new string[]
			{
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
		);
	}

	private string PluginPath
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModuleDirectory, "../..")).Replace("\\", "/");
		}
	}

	private string Plugin
	{
		get
		{
			return new DirectoryInfo(PluginPath).Name;
		}
	}

	private void Trace(string msg)
	{
		Console.WriteLine(Plugin + ": " + msg);
	}

	private void Trace(string format, params object[] args)
	{
		Trace(string.Format(format, args));
	}

	private void Fail(string message)
	{
		Trace(message);
		throw new Exception(message);
	}

	private void LoadLibrary(ReadOnlyTargetRules target, string[] includePaths, string libraryPath, bool recursiveSearch = true)
	{
		foreach (string includePath in includePaths)
		{
			string fullIncludePath = Path.Combine(PluginPath, includePath).Replace("\\", "/");

			if (recursiveSearch)
			{
				string[] subPaths = Directory.GetDirectories(fullIncludePath, "*", SearchOption.AllDirectories);

				PublicIncludePaths.Add(fullIncludePath);

				foreach (string path in subPaths)
				{
					PublicIncludePaths.Add(path);
				}
			}
		}

		// Get the build path
		var fullLibraryPath = Path.Combine(PluginPath, libraryPath);
		if (!File.Exists(fullLibraryPath))
		{
			Fail("Invalid build path: " + fullLibraryPath + " (Did you build the 3rdparty module already?)");
		}

		// Found a library; add it to the dependencies list
		if (fullLibraryPath.EndsWith(".lib"))
		{
			PublicAdditionalLibraries.Add(fullLibraryPath);
		}
		else
		{
			PublicAdditionalLibraries.Add(fullLibraryPath);
		}

		Trace("Added library: {0}", fullLibraryPath);
	}
}