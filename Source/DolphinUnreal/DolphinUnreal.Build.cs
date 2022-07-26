// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using System.Linq;
using UnrealBuildTool;

public class DolphinUnreal : ModuleRules
{
	private struct IncludePath
    {
		public string Path { get; set; }

		public bool IsRecursive { get; set; }

		public IncludePath(string path, bool isRecursive)
		{
			this.Path = path;
			this.IsRecursive = isRecursive;
		}
	};

	public DolphinUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		LoadLibrary(
			Target,
			new IncludePath[]
			{
				new IncludePath("ThirdParty/DolphinAPI/", false),
				new IncludePath("ThirdParty/DolphinAPI/dolphin-ipc/", false),
				new IncludePath("ThirdParty/DolphinAPI/dolphin-ipc/external/", false),
				new IncludePath("ThirdParty/DolphinAPI/dolphin-ipc/external/cereal", false),
				new IncludePath("ThirdParty/DolphinAPI/dolphin-ipc/external/cpp-ipc/include", false),
			},
			new string[]
			{
				"ThirdParty/DolphinAPI/dolphin-ipc/external/cpp-ipc/lib/Release/ipc.lib",
				"ThirdParty/DolphinAPI/Build/x64/Release/DolphinIPC.lib",
			}
		);

		CopyDolphinInstanceBinary();

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
				"Projects",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"EditorStyle",
				"UnrealEd",
				"GraphEditor",
				"BlueprintGraph",
				"Kismet",
				"KismetCompiler",
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

	private void LoadLibrary(ReadOnlyTargetRules target, IncludePath[] includePaths, string[] libraryPaths)
	{
		foreach (IncludePath includePath in includePaths)
		{
			string fullIncludePath = Path.Combine(PluginPath, includePath.Path).Replace("\\", "/");

			PublicIncludePaths.Add(fullIncludePath);

			if (includePath.IsRecursive)
			{
				string[] subPaths = Directory.GetDirectories(fullIncludePath, "*", SearchOption.AllDirectories);

				foreach (string path in subPaths)
				{
					PublicIncludePaths.Add(path);
				}
			}
		}

		// Get the build path
		foreach (string libraryPath in libraryPaths)
		{
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

	private void CopyDolphinInstanceBinary()
	{
		string binaryReleasePath = Path.Combine(PluginPath, "ThirdParty/DolphinAPI/Build/x64/Release/DolphinInstance.exe");
		string binaryContentPath = Path.Combine(PluginPath, "Content/Dolphin/DolphinInstance.exe");

		if (File.Exists(binaryReleasePath))
		{
			File.Copy(binaryReleasePath, binaryContentPath, true);
		}
	}
}
