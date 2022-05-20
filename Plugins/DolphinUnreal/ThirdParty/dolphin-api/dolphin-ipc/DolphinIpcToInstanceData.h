#pragma once
// Defines the IPC methods that are called from the controlling library (server) to an individual Dolphin instance (client)

#include "external/cereal/cereal.hpp"

#include <string>

enum class DolphinInstanceIpcCall
{
    Null,
	ToInstanceParams_WaitFrames,
    DolphinInstance_Connect,
    DolphinInstance_LoadGame,
};

struct ToInstanceParams_WaitFrames
{
	int _frames;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_frames);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_frames);
	}
};

struct ToInstanceParams_Connect
{
    std::string _channelName;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_channelName);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_channelName);
	}
};

struct ToInstanceParams_LoadGame
{
    std::string _title;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_title);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_title);
	}
};

struct DolphinIpcToInstanceData
{
    DolphinInstanceIpcCall _call = DolphinInstanceIpcCall::Null;

    union
    {
		ToInstanceParams_WaitFrames* _waitFramesParams;
		ToInstanceParams_Connect* _connectParams;
        ToInstanceParams_LoadGame* _loadGameParams;
    } _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_call);

		switch (_call)
		{
			case DolphinInstanceIpcCall::ToInstanceParams_WaitFrames: ar(*_params._waitFramesParams); break;
			case DolphinInstanceIpcCall::DolphinInstance_Connect: ar(*_params._connectParams); break;
			case DolphinInstanceIpcCall::DolphinInstance_LoadGame: ar(*_params._loadGameParams); break;
			case DolphinInstanceIpcCall::Null: default: break;
		}
	}

	template <class Archive>
	void load(Archive& ar)
	{
		ar(_call);

		switch (_call)
		{
			case DolphinInstanceIpcCall::ToInstanceParams_WaitFrames:
				_params._waitFramesParams = new ToInstanceParams_WaitFrames();
				ar(*(_params._waitFramesParams));
				break;
			case DolphinInstanceIpcCall::DolphinInstance_Connect:
				_params._connectParams = new ToInstanceParams_Connect();
				ar(*(_params._connectParams));
				break;
			case DolphinInstanceIpcCall::DolphinInstance_LoadGame:
				_params._loadGameParams = new ToInstanceParams_LoadGame();
				ar(*(_params._loadGameParams));
				break;
			case DolphinInstanceIpcCall::Null: default: break;
		}
	}
};
