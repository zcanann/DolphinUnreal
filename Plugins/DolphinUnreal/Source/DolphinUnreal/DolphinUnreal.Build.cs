// Some copyright should be here...

using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using UnrealBuildTool;

public class DolphinUnreal : ModuleRules
{
	public DolphinUnreal(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		LoadLibrary(target,
			new string[]
			{
				"ThirdParty/dolphin/Source",
				"ThirdParty/dolphin/Externals/",
			},
			new string[]
			{
				"ThirdParty/dolphin/Externals/mGBA/",
			},
			"ThirdParty/dolphin/Build/x64/Release/DolphinLib/bin/",
			"DolphinLib"
		);

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);
				
		
		PrivateIncludePaths.AddRange(
			new string[]
			{
				// ... add other private include paths required here ...
			}
		);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
		);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
		);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
	}

	/** Get the name of this plugin's folder */
	private string Plugin
	{
		get
		{
			return new DirectoryInfo(PluginPath).Name;
		}
	}

	/** Get the absolute root to the plugin folder */
	private string PluginPath
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModuleDirectory, "../.."));
		}
	}

	private void Trace(string msg)
	{
		Console.WriteLine(msg);
	}

	/** Trace helper */
	private void Trace(string format, params object[] args)
	{
		Trace(string.Format(format, args));
	}

	/** Raise an error */
	private void Fail(string message)
	{
		Trace(message);
		throw new Exception(message);
	}


	/**
	 * Helper to setup an arbitrary library in the given library folder
	 * @param include_path Relative include path, eg. 3rdparty/mylib/include
	 * @param build_path Relative build path, eg. 3rdparty/mylib/build
	 * @param library_name Short library name, eg. mylib. Automatically expands to libmylib.a, mylib.lib, etc.
	 */
	private void LoadLibrary(ReadOnlyTargetRules target, string[] includePaths, string[] excludePaths, string buildPath, string libraryName)
	{
		List<string> excludePathsFull = new List<string>();

		foreach (string excludePath in excludePaths)
		{
			string fullExcludePath = Path.Combine(PluginPath, excludePath).Replace("\\", "/");
			excludePathsFull.Add(fullExcludePath);
		}

		// Add the include paths
		foreach (string includePath in includePaths)
		{
			string fullIncludePath = Path.Combine(PluginPath, includePath);
			string[] directories = Directory.GetDirectories(fullIncludePath, "*", SearchOption.AllDirectories);

			PublicIncludePaths.Add(fullIncludePath);

			foreach (string path in directories)
			{
				string searchPath = path.Replace("\\", "/");
				if (excludePathsFull.Any(excludePath => searchPath.StartsWith(excludePath)))
                {
					Console.WriteLine("SKIPPED: " + searchPath);
					continue;
                }

				if (!Directory.Exists(searchPath))
				{
					Fail("Invalid include path: " + searchPath);
				}
				else
				{
					PublicIncludePaths.Add(path);
					Trace("Added include path: {0}", searchPath);
				}
			}
		}

		// Get the build path
		var fullBuildPath = Path.Combine(PluginPath, buildPath);
		if (!Directory.Exists(fullBuildPath))
		{
			Fail("Invalid build path: " + fullBuildPath + " (Did you build the 3rdparty module already?)");
		}

		// Look at all the files in the build path; we need to smartly locate
		// the static library based on the current platform. For dynamic libraries
		// this is more difficult, but for static libraries, it's just .lib or .a
		string[] fileEntries = Directory.GetFiles(fullBuildPath);
		string fullLibraryPath = null;
		foreach (string file in fileEntries)
		{
			string fileName = Path.GetFileName(file);
			string suffix = target.Platform == UnrealTargetPlatform.Win64 ? "lib" : "a";

			if (fileName.StartsWith(libraryName) && fileName.EndsWith(suffix))
			{
				fullLibraryPath = Path.Combine(fullBuildPath, file);
				break;
			}
		}

		if (fullLibraryPath == null)
		{
			Fail("Unable to locate any build libraries in: " + fullBuildPath);
		}

		// Found a library; add it to the dependencies list
		PublicAdditionalLibraries.Add(fullLibraryPath);
		Trace("Added static library: {0}", fullLibraryPath);
	}
}
