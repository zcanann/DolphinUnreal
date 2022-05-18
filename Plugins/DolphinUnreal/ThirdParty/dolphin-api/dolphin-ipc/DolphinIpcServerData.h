#pragma once
// Defines the IPC callbacks that are called from an individual Dolphin instance (client) to the controlling library (server)

#include "external/cereal/cereal.hpp"

#include <string>

enum class DolphinServerIpcCall
{
	Null,
	DolphinServer_OnClientConnected,
	DolphinServer_OnClientTerminated,
};

struct DolphinServer_OnClientConnected
{
	std::string _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_params);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_params);
	}
};

struct DolphinServer_OnClientTerminated
{
	std::string _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_params);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_params);
	}
};

struct DolphinIpcServerData
{
	DolphinServerIpcCall _call = DolphinServerIpcCall::Null;

	union
	{
		DolphinServer_OnClientConnected* _onClientConnectedParams;;
		DolphinServer_OnClientTerminated* _onClientTerminatedParams;
	} _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		switch (_call)
		{
			case DolphinServerIpcCall::DolphinServer_OnClientConnected: ar(_call, *_params._onClientConnectedParams); break;
			case DolphinServerIpcCall::DolphinServer_OnClientTerminated: ar(_call, *_params._onClientTerminatedParams); break;
			case DolphinServerIpcCall::Null: default: break;
		}
	}

	template <class Archive>
	void load(Archive& ar)
	{
		ar(_call);

		switch (_call)
		{
			case DolphinServerIpcCall::DolphinServer_OnClientConnected:
			{
				_params._onClientConnectedParams = new DolphinServer_OnClientConnected();
				ar(*(_params._onClientConnectedParams));
				break;
			}
			case DolphinServerIpcCall::DolphinServer_OnClientTerminated:
			{
				_params._onClientTerminatedParams = new DolphinServer_OnClientTerminated();
				ar(*(_params._onClientTerminatedParams));
				break;
			}
			case DolphinServerIpcCall::NONE: default: break;
		}
	}
};
