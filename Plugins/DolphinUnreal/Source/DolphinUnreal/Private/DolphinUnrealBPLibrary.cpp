// Copyright Epic Games, Inc. All Rights Reserved.

#include "DolphinUnrealBPLibrary.h"
#include "DolphinUnreal.h"

// Dolphin flags
#undef HAS_LIBMGBA
#define FMT_HEADER_ONLY

// Dolphin includes
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <signal.h>
#include <string>
#include <vector>

#include "Common/StringUtil.h"
#include "Core/Boot/Boot.h"
#include "Core/BootManager.h"
#include "Core/Core.h"
#include "Core/Host.h"
#include "InputCommon/GCAdapter.h"
#include "UICommon/UICommon.h"
#include "VideoCommon/RenderBase.h"
#include "VideoCommon/VideoBackendBase.h"

UDolphinUnrealBPLibrary::UDolphinUnrealBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UDolphinUnrealBPLibrary::CreateDolphinInstance()
{
    std::optional<std::string> save_state_path = { };
    const std::list<std::string> paths_list = { };
    const std::vector<std::string> paths{ std::make_move_iterator(std::begin(paths_list)), std::make_move_iterator(std::end(paths_list)) };
    std::unique_ptr<BootParameters> boot = BootParameters::GenerateFromFile(paths, BootSessionData(save_state_path, DeleteSavestateAfterBoot::No));
    bool bGameSpecified = true;
    std::string user_directory;

    UICommon::SetUserDirectory(user_directory);
    UICommon::Init();
    // GCAdapter::Init();
    /*
    std::string s_platform = "win32";

    Core::AddOnStateChangedCallback([](Core::State state)
    {
        // if (state == Core::State::Uninitialized)
            // s_platform->Stop();
    });*/

#ifdef _WIN32
    // signal(SIGINT, signal_handler);
    // signal(SIGTERM, signal_handler);
#else
    // Shut down cleanly on SIGINT and SIGTERM
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;
    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
#endif

    /*
    if (!BootManager::BootCore(std::move(boot), s_platform->GetWindowSystemInfo()))
    {
        fprintf(stderr, "Could not boot the specified file\n");
        return 1;
    }*/

    /*
    // s_platform->MainLoop();
    Core::Stop();

    Core::Shutdown();
    // s_platform.reset();
    UICommon::Shutdown();*/
}
