#pragma once
#include <functional>
#include <vector>
#include "LGR.h"
#include <string>
#include "Events.h"
#include "Generic.h"

class EventHandler
{
public:
	enum EventType {
		touchApple,
		touchFlower
	};

	enum EventAction {
		dosomething,
		dosomethingelse
	};

	struct eventStruct
	{
		EventType type;
		std::function<void(std::vector<std::string>)> func;
		std::vector<std::string> args;
		eventStruct(EventType t, std::function<void(std::vector<std::string>)> f, std::vector<std::string> a) 
		{
			type = t;
			func = f;
			args = a;
		}
	};

	static std::vector<std::string> ConvertArgs(const char* args);

	static std::function<void(std::vector<std::string>)> Create(EventAction action);

	static void AddEvent(EventType type, EventAction action, std::vector<std::string> args);

	static void RemoveEvent(EventType type, EventAction action);

	static void Trigger(EventType type);

	static std::vector<eventStruct> Events;

};

