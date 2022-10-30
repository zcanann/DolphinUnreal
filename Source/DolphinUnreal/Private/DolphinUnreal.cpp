// Copyright Epic Games, Inc. All Rights Reserved.

#include "DolphinUnreal.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include <shellapi.h>
#include "Windows/HideWindowsPlatformTypes.h"

#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "ISequencerModule.h"
#include "Timeline/FrameInputsTrackEditor.h"
#include "ToolMenus.h"

#include "DataTypes/DolphinDataTypesBlueprintLibrary.h"
#include "DolphinInstance.h"
#include "DolphinUnrealStyle.h"

#define LOCTEXT_NAMESPACE "FDolphinUnrealModule"

DEFINE_LOG_CATEGORY(Dolphin);

const FName FDolphinUnrealModule::ModuleName = FName("DolphinUnreal");

void FDolphinUnrealModule::StartupModule()
{
	FDolphinUnrealStyle::Register();
	UDolphinDataTypesBlueprintLibrary::AutoFavoriteCommonDolphinFunctions();
	RegisterQuickSettingsMenu();

	ISequencerModule& SequencerModule = FModuleManager::Get().LoadModuleChecked<ISequencerModule>("Sequencer");
	TrackEditorBindingHandle = SequencerModule.RegisterPropertyTrackEditor<FFrameInputsTrackEditor>();
}

void FDolphinUnrealModule::ShutdownModule()
{
	FDolphinUnrealStyle::Unregister();

	ISequencerModule* SequencerModule = FModuleManager::GetModulePtr<ISequencerModule>("Sequencer");
	if (SequencerModule)
	{
		SequencerModule->UnRegisterTrackEditor(TrackEditorBindingHandle);
	}
}

UDolphinInstance* FDolphinUnrealModule::CreateNewInstance()
{
	UDolphinInstance* Instance = NewObject<UDolphinInstance>();

	Instance->AddToRoot();

	return Instance;
}

void FDolphinUnrealModule::TerminateInstance(UDolphinInstance* InDolphinInstance)
{
	if (InDolphinInstance != nullptr)
	{
		FDolphinUnrealModule::UntrackInstance(InDolphinInstance);
		InDolphinInstance->ConditionalBeginDestroy();
		InDolphinInstance->RemoveFromRoot();
	}
}

void FDolphinUnrealModule::TrackInstance(UDolphinInstance* InDolphinInstance)
{
	DolphinInstances.Add(InDolphinInstance);
}

void FDolphinUnrealModule::UntrackInstance(UDolphinInstance* InDolphinInstance)
{
	DolphinInstances.Remove(InDolphinInstance);
}

TArray<UDolphinInstance*> FDolphinUnrealModule::GetDolphinInstances() const
{
	return DolphinInstances;
}

void FDolphinUnrealModule::RegisterQuickSettingsMenu()
{
	UToolMenu* Menu = UToolMenus::Get()->RegisterMenu("LevelEditor.LevelEditorToolBar.LevelToolbarQuickSettings");

	struct Local
	{
		static void OpenDolphinSettings()
		{
			static FString PluginContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());
			static FString ProjectContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());

			FString UserPath = FPaths::Combine(ProjectContentDirectory, "Dolphin");
			FString Params = FString::Format(TEXT("-u \"{0}\""), { UserPath });

			FString DolphinBinaryFolder = FPaths::Combine(PluginContentDirectory, TEXT("Dolphin/"));
			FString DolphinBinaryPath = FPaths::Combine(DolphinBinaryFolder, TEXT("Dolphin.exe"));
			FString OptionalWorkingDirectory = DolphinBinaryFolder;

			ShellExecute(NULL, TEXT("open"), *DolphinBinaryPath, *Params, *OptionalWorkingDirectory, SW_SHOWDEFAULT);
		}
	};

	{
		FToolMenuSection& Section = Menu->AddSection("DolphinSettingsSection", LOCTEXT("DolphinSettings", "Dolphin Settings"));

		Section.AddMenuEntry(
			"ProjectSettings",
			LOCTEXT("ProjectSettingsMenuLabel", "Dolphin Settings..."),
			LOCTEXT("ProjectSettingsMenuToolTip", "Change the Dolphin settings for this TAS. WARNING: Changing some settings may cause desyncs!"),
			FSlateIcon(FEditorStyle::GetStyleSetName(), "ProjectSettings.TabIcon"),
			FUIAction(FExecuteAction::CreateStatic(&Local::OpenDolphinSettings))
		);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDolphinUnrealModule, DolphinUnreal)
