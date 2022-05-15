
// Lib dependencies
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "setupapi.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "swresample.lib")
#pragma comment(lib, "swscale.lib")
#pragma comment(lib, "Bcrypt.lib")
#pragma comment(lib, "cubeb.lib")
#pragma comment(lib, "Avrt.lib")

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
#ifdef USE_DISCORD_PRESENCE
#include "UICommon/DiscordPresence.h"
#endif
#include "UICommon/UICommon.h"
#include "VideoCommon/RenderBase.h"
#include "VideoCommon/VideoBackendBase.h"

// static std::unique_ptr<Platform> s_platform;

static void signal_handler(int)
{
    const char message[] = "A signal was received. A second signal will force Dolphin to stop.\n";
#ifdef _WIN32
    puts(message);
#else
    if (write(STDERR_FILENO, message, sizeof(message)) < 0)
    {
    }
#endif

    // s_platform->RequestShutdown();
}

std::vector<std::string> Host_GetPreferredLocales()
{
    return {};
}

void Host_NotifyMapLoaded()
{
}

void Host_RefreshDSPDebuggerWindow()
{
}

bool Host_UIBlocksControllerState()
{
    return false;
}

static Common::Event s_update_main_frame_event;
void Host_Message(HostMessageID id)
{
    // if (id == HostMessageID::WMUserStop)
        //  s_platform->Stop();
}

void Host_UpdateTitle(const std::string& title)
{
    // s_platform->SetTitle(title);
}

void Host_UpdateDisasmDialog()
{
}

void Host_UpdateMainFrame()
{
    // s_update_main_frame_event.Set();
}

void Host_RequestRenderWindowSize(int width, int height)
{
}

bool Host_RendererHasFocus()
{
    return 0;// s_platform->IsWindowFocused();
}

bool Host_RendererHasFullFocus()
{
    // Mouse capturing isn't implemented
    return Host_RendererHasFocus();
}

bool Host_RendererIsFullscreen()
{
    return false; // s_platform->IsWindowFullscreen();
}

void Host_YieldToUI()
{
}

void Host_TitleChanged()
{
#ifdef USE_DISCORD_PRESENCE
    Discord::UpdateDiscordPresence();
#endif
}

std::unique_ptr<GBAHostInterface> Host_CreateGBAHost(std::weak_ptr<HW::GBA::Core> core)
{
    return nullptr;
}

void DolphinInit()
{
    std::optional<std::string> save_state_path = { };
    const std::list<std::string> paths_list = { };
    const std::vector<std::string> paths{ std::make_move_iterator(std::begin(paths_list)), std::make_move_iterator(std::end(paths_list)) };
    std::unique_ptr<BootParameters> boot = BootParameters::GenerateFromFile(paths, BootSessionData(save_state_path, DeleteSavestateAfterBoot::No));
    // bool bGameSpecified = true;
    std::string user_directory;

    UICommon::SetUserDirectory(user_directory);
    UICommon::Init();
    GCAdapter::Init();
    /*
    std::string s_platform = "win32";

    Core::AddOnStateChangedCallback([](Core::State state)
    {
        // if (state == Core::State::Uninitialized)
            // s_platform->Stop();
    });*/

#ifdef _WIN32
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
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

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            DolphinInit();
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
        {
            break;
        }
    }

    return TRUE;
}

