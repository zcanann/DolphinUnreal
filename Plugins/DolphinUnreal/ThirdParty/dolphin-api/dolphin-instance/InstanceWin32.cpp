// Copyright 2019 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Instance.h"

#include "Common/MsgHandler.h"
#include "Core/Config/MainSettings.h"
#include "Core/ConfigManager.h"
#include "Core/Core.h"
#include "Core/State.h"

#include <Windows.h>
#include <climits>
#include <cstdio>

#include "VideoCommon/RenderBase.h"
#include "resource.h"

class InstanceWin32 : public Instance
{
public:
    InstanceWin32(const std::string& instanceId);
    ~InstanceWin32() override;

    bool Init() override;
    void SetTitle(const std::string& string) override;
    void MainLoop() override;

    WindowSystemInfo GetWindowSystemInfo() const;
    
private:
    static constexpr TCHAR WINDOW_CLASS_NAME[] = _T("Dolphin");

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    bool RegisterRenderWindowClass();
    bool CreateRenderWindow();
    void UpdateWindowPosition();
    void ProcessEvents();

    HWND _hwnd{};

    int _window_x = Config::Get(Config::MAIN_RENDER_WINDOW_XPOS);
    int _window_y = Config::Get(Config::MAIN_RENDER_WINDOW_YPOS);
    int _window_width = Config::Get(Config::MAIN_RENDER_WINDOW_WIDTH);
    int _window_height = Config::Get(Config::MAIN_RENDER_WINDOW_HEIGHT);
};

InstanceWin32::InstanceWin32(const std::string& instanceId) : Instance(instanceId)
{
}

InstanceWin32::~InstanceWin32()
{
    if (_hwnd)
    {
        DestroyWindow(_hwnd);
    }
}

bool InstanceWin32::RegisterRenderWindowClass()
{
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.hIcon = LoadIcon(NULL, IDI_ICON1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = WINDOW_CLASS_NAME;
    wc.hIconSm = LoadIcon(NULL, IDI_ICON1);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, _T("Window registration failed."), _T("Error"), MB_ICONERROR | MB_OK);
        return false;
    }

    return true;
}

bool InstanceWin32::CreateRenderWindow()
{
    _hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, WINDOW_CLASS_NAME, _T("Dolphin"), WS_OVERLAPPEDWINDOW,
    _window_x < 0 ? CW_USEDEFAULT : _window_x,
    _window_y < 0 ? CW_USEDEFAULT : _window_y, _window_width,
    _window_height, nullptr, nullptr, GetModuleHandle(nullptr), this);

    if (!_hwnd)
    {
        MessageBox(nullptr, _T("CreateWindowEx failed."), _T("Error"), MB_ICONERROR | MB_OK);
        return false;
    }

    ShowWindow(_hwnd, SW_SHOW);
    UpdateWindow(_hwnd);
    return true;
}

bool InstanceWin32::Init()
{
    if (!RegisterRenderWindowClass() || !CreateRenderWindow())
    {
        return false;
    }

    // TODO: Enter fullscreen if enabled.
    if (Config::Get(Config::MAIN_FULLSCREEN))
    {
        ProcessEvents();
    }

    if (Config::Get(Config::MAIN_DISABLE_SCREENSAVER))
    {
        SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);
    }

    UpdateWindowPosition();
    return Instance::Init();
}

void InstanceWin32::SetTitle(const std::string& string)
{
    SetWindowTextW(_hwnd, UTF8ToWString(string).c_str());
}

void InstanceWin32::MainLoop()
{
    while (IsRunning())
    {
        UpdateRunningFlag();
        Core::HostDispatchJobs();
        ProcessEvents();
        UpdateWindowPosition();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

WindowSystemInfo InstanceWin32::GetWindowSystemInfo() const
{
    WindowSystemInfo wsi;
    wsi.type = WindowSystemType::Windows;
    wsi.render_window = reinterpret_cast<void*>(_hwnd);
    wsi.render_surface = reinterpret_cast<void*>(_hwnd);
    return wsi;
}

void InstanceWin32::UpdateWindowPosition()
{
    if (_window_fullscreen)
    {
        return;
    }

    RECT rc = {};
    if (!GetWindowRect(_hwnd, &rc))
    {
        return;
    }

    _window_x = rc.left;
    _window_y = rc.top;
    _window_width = rc.right - rc.left;
    _window_height = rc.bottom - rc.top;
}

void InstanceWin32::ProcessEvents()
{
    MSG msg;
    while (PeekMessage(&msg, _hwnd, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT InstanceWin32::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    InstanceWin32* platform = reinterpret_cast<InstanceWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    switch (msg)
    {
        case WM_NCCREATE:
        {
            platform = reinterpret_cast<InstanceWin32*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(platform));
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
        case WM_SIZE:
        {
            if (g_renderer)
            {
                g_renderer->ResizeSurface();
            }
            break;
        }
        case WM_CLOSE:
        {
            platform->RequestShutdown();
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    }

    return 0;
}

std::unique_ptr<Instance> Instance::CreateWin32Instance(const std::string& instanceId)
{
    return std::make_unique<InstanceWin32>(instanceId);
}
