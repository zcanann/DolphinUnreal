// Copyright 2018 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <memory>
#include <string>

#include "Common/Flag.h"
#include "Common/WindowSystemInfo.h"

class IpcCommandHandler;

class Instance
{
public:
	Instance(const std::string& channelId);
	virtual ~Instance();

	bool IsRunning() const { return _running.IsSet(); }
	bool IsWindowFocused() const { return _window_focus; }
	bool IsWindowFullscreen() const { return _window_fullscreen; }

	virtual bool Init();
	virtual void SetTitle(const std::string& title);
	virtual void MainLoop() = 0;

	virtual WindowSystemInfo GetWindowSystemInfo() const = 0;

	// Requests a graceful shutdown, from SIGINT/SIGTERM.
	void RequestShutdown();

	// Request an immediate shutdown.
	void Stop();

	static std::unique_ptr<Instance> CreateHeadlessInstance(const std::string& channelId);
#ifdef HAVE_X11
	static std::unique_ptr<Instance> CreateX11Instance(const std::string& channelId);
#endif

#ifdef __linux__
	static std::unique_ptr<Instance> CreateFBDevInstance(const std::string& channelId);
#endif

#ifdef _WIN32
	static std::unique_ptr<Instance> CreateWin32Instance(const std::string& channelId);
#endif

protected:
	void UpdateRunningFlag();

	IpcCommandHandler* _ipcCommandHandler = nullptr;

	Common::Flag _running{true};
	Common::Flag _shutdown_requested{false};
	Common::Flag _tried_graceful_shutdown{false};

	bool _window_focus = true;  // Should be made atomic if actually implemented
	bool _window_fullscreen = false;
};
