#pragma once
// Defines the IPC callbacks that are called from an individual Dolphin instance (client) to the controlling library (server)

#include "external/cereal/cereal.hpp"

#include <string>

enum class DolphinServerIpcCall
{
	Null,
	DolphinServer_OnInstanceConnected,
	DolphinServer_OnInstanceTerminated,
};

struct ToServerParams_OnInstanceConnected
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

struct ToServerParams_OnInstanceTerminated
{
	std::string _params1;
	std::string _params2;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_params1);
		ar(_params2);
	}
	template <class Archive>
	void load(Archive& ar)
	{
		ar(_params1);
		ar(_params2);
	}
};

struct DolphinIpcToServerData
{
	~DolphinIpcToServerData()
	{
		switch (_call)
		{
			case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: delete _params._onInstanceConnectedParams; break;
			case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: delete _params._onInstanceTerminatedParams; break;
			case DolphinServerIpcCall::Null: default: break;
		}
	}

	DolphinServerIpcCall _call = DolphinServerIpcCall::Null;

	union
	{
		ToServerParams_OnInstanceConnected* _onInstanceConnectedParams;
		ToServerParams_OnInstanceTerminated* _onInstanceTerminatedParams;
	} _params;

	template <class Archive>
	void save(Archive& ar) const
	{
		ar(_call);

		switch (_call)
		{
			case DolphinServerIpcCall::DolphinServer_OnInstanceConnected: ar(*_params._onInstanceConnectedParams); break;
			case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated: ar(*_params._onInstanceTerminatedParams); break;
			case DolphinServerIpcCall::Null: default: break;
		}
	}

	template <class Archive>
	void load(Archive& ar)
	{
		ar(_call);
		
		switch (_call)
		{
			case DolphinServerIpcCall::DolphinServer_OnInstanceConnected:
			{
				_params._onInstanceConnectedParams = new ToServerParams_OnInstanceConnected();
				ar(*(_params._onInstanceConnectedParams));
				break;
			}
			case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated:
			{
				_params._onInstanceTerminatedParams = new ToServerParams_OnInstanceTerminated();
				ar(*(_params._onInstanceTerminatedParams));
				break;
			}
			case DolphinServerIpcCall::Null: default: break;
		}
	}
};
