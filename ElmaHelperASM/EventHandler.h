#pragma once
#include <vector>
#include "LGR.h"
#include <string>
#include "Events.h"
#include "Common.h"

class EventHandler
{
public:
	enum TriggerType {
		touchApple,
		touchFlower
	};

	struct eventStruct
	{
		TriggerType type;
		std::function<void(std::vector<std::string>)> func;
		std::vector<std::string> args;
		eventStruct(TriggerType t, std::function<void(std::vector<std::string>)> f, std::vector<std::string> a) 
		{
			type = t;
			func = f;
			args = a;
		}
	};

	static std::vector<std::string> ConvertArgs(const char* args);

	static std::function<void(std::vector<std::string>)> Create(std::string action);

	static void AddEvent(TriggerType type, std::string action, std::vector<std::string> args);

	static void RemoveEvent(TriggerType type, std::string action);

	static void Trigger(TriggerType type);

	static std::vector<eventStruct> Events;

};

