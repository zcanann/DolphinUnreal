// Copyright 2018 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Instance.h"

#include "Core/IOS/IOS.h"
#include "Core/IOS/STM/STM.h"
#include "Core/State.h"

#include "IpcCommandHandler.h"

namespace ProcessorInterface
{
    void PowerButton_Tap();
}

Instance::Instance(const std::string& instanceId)
{
    _ipcCommandHandler = std::make_shared<IpcCommandHandler>();
    _ipcCommandHandler->initializeChannels(instanceId);

    // Ipc post-connect callback
    /*
    DolphinIpcServerData ipcData;
    auto data = std::shared_ptr<DolphinParams_OnInstanceConnected>(new DolphinParams_OnInstanceConnected());
    ipcData._params._onInstanceConnectedParams = data.get();
    _ipcCommandHandler->ipcSendToServer(ipcData);
    */
}

Instance::~Instance()
{
}

bool Instance::Init()
{
  return true;
}

void Instance::SetTitle(const std::string& title)
{
}

void Instance::UpdateRunningFlag()
{
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
