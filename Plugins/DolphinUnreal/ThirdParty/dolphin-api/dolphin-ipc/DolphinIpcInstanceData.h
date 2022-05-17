#pragma once
// Defines the IPC methods that are called from the controlling library (server) to an individual Dolphin instance (client)

#include "external/cereal/cereal.hpp"

#include <string>

enum class DolphinInstanceIpcCall
{
    Null,
    DolphinInstance_Connect,
    DolphinInstance_LoadGame,
};

struct DolphinParams_Connect
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

struct DolphinParams_LoadGame
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

struct DolphinIpcInstanceData
{
    DolphinInstanceIpcCall _call = DolphinInstanceIpcCall::Null;

    union
    {
        DolphinParams_Connect* _connectParams;
        DolphinParams_LoadGame* _loadGameParams;
    } _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		switch (_call)
		{
			case DolphinInstanceIpcCall::DolphinInstance_Connect: ar(_call, *_params._connectParams); break;
			case DolphinInstanceIpcCall::DolphinInstance_LoadGame: ar(_call, *_params._loadGameParams); break;
			case DolphinInstanceIpcCall::Null: default: break;
		}
	}

	template <class Archive>
	void load(Archive& ar)
	{
		ar(_call);

		switch (_call)
		{
			case DolphinInstanceIpcCall::DolphinInstance_Connect:
				_params._connectParams = new DolphinParams_Connect();
				ar(*(_params._connectParams));
				break;
			case DolphinInstanceIpcCall::INT_KEY_MAP:
				_params._loadGameParams = new DolphinParams_LoadGame();
				ar(*(_params._loadGameParams));
				break;
			case DolphinInstanceIpcCall::NONE: default: break;
		}
	}
};
