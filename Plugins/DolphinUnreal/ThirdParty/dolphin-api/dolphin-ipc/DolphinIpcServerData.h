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

struct DolphinParams_OnInstanceConnected
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

struct DolphinParams_OnInstanceTerminated
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

struct DolphinIpcServerData
{
	DolphinServerIpcCall _call = DolphinServerIpcCall::Null;

	union
	{
		DolphinParams_OnInstanceConnected* _onInstanceConnectedParams;
		DolphinParams_OnInstanceTerminated* _onInstanceTerminatedParams;
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
				_params._onInstanceConnectedParams = new DolphinParams_OnInstanceConnected();
				ar(*(_params._onInstanceConnectedParams));
				break;
			}
			case DolphinServerIpcCall::DolphinServer_OnInstanceTerminated:
			{
				_params._onInstanceTerminatedParams = new DolphinParams_OnInstanceTerminated();
				ar(*(_params._onInstanceTerminatedParams));
				break;
			}
			case DolphinServerIpcCall::Null: default: break;
		}
	}
};
