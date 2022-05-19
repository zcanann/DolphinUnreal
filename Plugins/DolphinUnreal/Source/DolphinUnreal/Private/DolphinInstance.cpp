#include "DolphinInstance.h"

#include "DolphinUnreal.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/MonitoredProcess.h"
#include "Misc/Paths.h"

// STL
#include <random>
#include <string>

UDolphinInstance::UDolphinInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{

}

void UDolphinInstance::Initialize(FDolphinGraphicsSettings InGraphicsSettings, FDolphinRuntimeSettings InRuntimeSettings)
{
    LaunchInstance();
}

UDolphinInstance::~UDolphinInstance()
{
}

void UDolphinInstance::LaunchInstance()
{
    static FString ContentDirectory = FPaths::ConvertRelativePathToFull(IPluginManager::Get().FindPlugin(TEXT("DolphinUnreal"))->GetContentDir());

    InstanceId = MakeInstanceId();
    FString DolphinPath = FPaths::Combine(ContentDirectory, TEXT("DolphinInstance.exe"));
    FString GamePath = TEXT("C:/Dolphin/Games/Star Fox Adventures (USA) (v1.00).iso");
    FString Params = FString::Format(TEXT("\"{0}\" -p win32 -i {1}"), { GamePath, InstanceId });
    bool bLaunchHidden = false;
    bool bCreatePipes = true;

    DolphinProcess = TSharedPtr<FMonitoredProcess>(new FMonitoredProcess(DolphinPath, Params, bLaunchHidden, bCreatePipes));
    DolphinProcess->Launch();

    initializeChannels(std::string(TCHAR_TO_UTF8(*InstanceId)));
}

FString UDolphinInstance::MakeInstanceId() const
{
    static std::random_device Device;
    static std::mt19937 Rand(Device());

    std::uniform_int_distribution<int> dist(0, 15);

    const char* Chars = "0123456789abcdef";
    const bool Dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    FString Result;

    for (int Index = 0; Index < 16; Index++)
    {
        if (Dash[Index])
        {
            Result += "-";
        }

        Result += Chars[dist(Rand)];
        Result += Chars[dist(Rand)];
    }
    return Result;
}
