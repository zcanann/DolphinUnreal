// Copyright 2022 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Instance.h"

#include "Core/Config/MainSettings.h"
#include "Core/Config/WiimoteSettings.h"
#include "Core/ConfigManager.h"
#include "Core/Core.h"
#include "Core/HW/Wiimote.h"
#include "Core/IOS/IOS.h"
#include "Core/IOS/STM/STM.h"
#include "Core/Movie.h"
#include "Core/State.h"
#include "Core/HW/DVD/DVDInterface.h"
#include "Core/HW/GBAPad.h"
#include "Core/HW/GCKeyboard.h"
#include "Core/HW/GCPad.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/HW/SI/SI_Device.h"
#include "Core/HW/Wiimote.h"
#include "Core/HW/WiimoteEmu/WiimoteEmu.h"
#include "InputCommon/ControllerInterface/ControllerInterface.h"
#include "InputCommon/GCAdapter.h"
#include "InputCommon/GCPadStatus.h"
#include "InputCommon/InputConfig.h"
#include "VideoCommon/VideoConfig.h"

#pragma optimize("", off)

namespace ProcessorInterface
{
    void PowerButton_Tap();
}

Instance::Instance(const std::string& instanceId)
{
    initializeChannels(instanceId, true);
}

Instance::~Instance()
{
}

bool Instance::Init()
{
    // Ipc post-connect callback
    DolphinIpcToServerData ipcData;
    ToServerParams_OnInstanceConnected* data = new ToServerParams_OnInstanceConnected();
    data->_params = "123";
    ipcData._call = DolphinServerIpcCall::DolphinServer_OnInstanceConnected;
    ipcData._params._onInstanceConnectedParams = data;
    ipcSendToServer(ipcData);

    InitControllers();
    PrepareForTASInput();

    return true;
}

void Instance::InitControllers()
{
    if (g_controller_interface.IsInit())
    {
        return;
    }

    g_controller_interface.Initialize(GetWindowSystemInfo());

    if (!g_controller_interface.HasDefaultDevice())
    {
        // Note that the CI default device could be still temporarily removed at any time
        WARN_LOG(CONTROLLERINTERFACE,
            "No default device has been added in time. EmulatedController(s) defaulting adds"
            " input mappings made for a specific default device depending on the platform");
    }

    GCAdapter::Init();
    Pad::Initialize();
    Pad::InitializeGBA();
    Keyboard::Initialize();
    Wiimote::Initialize(Wiimote::InitializeMode::DO_NOT_WAIT_FOR_WIIMOTES);

    // Defaults won't work reliabily without loading and saving the config first

    Wiimote::LoadConfig();
    Wiimote::GetConfig()->SaveConfig();

    Pad::LoadConfig();
    Pad::GetConfig()->SaveConfig();

    Pad::LoadGBAConfig();
    Pad::GetGBAConfig()->SaveConfig();

    Keyboard::LoadConfig();
    Keyboard::GetConfig()->SaveConfig();
}

void Instance::ShutdownControllers()
{
    Pad::Shutdown();
    Pad::ShutdownGBA();
    Keyboard::Shutdown();
    Wiimote::Shutdown();
    g_controller_interface.Shutdown();
}

void Instance::PrepareForTASInput()
{
    // Core::SetState(Core::State::Paused);

    Wiimote::ResetAllWiimotes();
    Core::UpdateWantDeterminism();
    Movie::SetReadOnly(false);
    Movie::SetGCInputManip([this](GCPadStatus* pad_status, int controller_id)
    {
        static int debug = 5;
        if (pad_status)
        {
            // pad_status->triggerRight = 255;
            // pad_status->button |= PadButton::PAD_TRIGGER_R;

            if (debug-- < 0)
            {
                pad_status->button |= PadButton::PAD_BUTTON_A;
                pad_status->button |= PadButton::PAD_BUTTON_START;
                debug = 5;
            }
        }
    });

    /*
    Movie::ControllerTypeArray controllers { };
    Movie::WiimoteEnabledArray wiimotes { };

    for (int index = 0; index < 4; index++)
    {
        const SerialInterface::SIDevices si_device = Config::Get(Config::GetInfoForSIDevice(index));

        if (si_device == SerialInterface::SIDEVICE_GC_GBA_EMULATED)
        {
            controllers[index] = Movie::ControllerType::GBA;
        }
        else if (SerialInterface::SIDevice_IsGCController(si_device))
        {
            controllers[index] = Movie::ControllerType::GC;
        }
        else
        {
            controllers[index] = Movie::ControllerType::None;
        }

        wiimotes[index] = Config::Get(Config::GetInfoForWiimoteSource(index)) != WiimoteSource::None;
    }

    // TODO: Potentially enable this if we want to support dumping DTM files
    // Movie::BeginRecordingInput(controllers, wiimotes);*/
}

void Instance::DolphinInstance_WaitFrames(const ToInstanceParams_WaitFrames& waitFramesParam)
{
}

void Instance::DolphinInstance_Connect(const ToInstanceParams_Connect& connectParams)
{

}

void Instance::DolphinInstance_LoadGame(const ToInstanceParams_LoadGame& loadGameParams)
{

}

void Instance::SetTitle(const std::string& title)
{
}

void Instance::UpdateRunningFlag()
{
    updateIpcListen();

    if (_shutdown_requested.TestAndClear())
    {
        const auto ios = IOS::HLE::GetIOS();
        const auto stm = ios ? ios->GetDeviceByName("/dev/stm/eventhook") : nullptr;
        if (!_tried_graceful_shutdown.IsSet() && stm &&
            std::static_pointer_cast<IOS::HLE::STMEventHookDevice>(stm)->HasHookInstalled())
        {
            ProcessorInterface::PowerButton_Tap();
            _tried_graceful_shutdown.Set();
        }
        else
        {
            _running.Clear();
        }
    }
}

void Instance::Stop()
{
    _running.Clear();
}

void Instance::RequestShutdown()
{
    _shutdown_requested.Set();
}
