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
#include "Core/HW/SI/SI_Device.h"
#include "InputCommon/GCPadStatus.h"

namespace ProcessorInterface
{
    void PowerButton_Tap();
}

Instance::Instance(const std::string& instanceId)
{
    initializeChannels(instanceId, true);

    // Ipc post-connect callback
    DolphinIpcToServerData ipcData;
    ToServerParams_OnInstanceConnected* data = new ToServerParams_OnInstanceConnected();
    data->_params = "123";
    ipcData._call = DolphinServerIpcCall::DolphinServer_OnInstanceConnected;
    ipcData._params._onInstanceConnectedParams = data;
    ipcSendToServer(ipcData);

    // Core::SetState(Core::State::Paused);

    Movie::SetReadOnly(false);
    Movie::SetGCInputManip([this](GCPadStatus* pad_status, int controller_id)
    {
        if (pad_status)
        {
            pad_status->triggerRight = 255;
            pad_status->button |= PadButton::PAD_TRIGGER_R;
        }
    });

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

    Movie::BeginRecordingInput(controllers, wiimotes);
}

Instance::~Instance()
{
}

bool Instance::Init()
{
  return true;
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
