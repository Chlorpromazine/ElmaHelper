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

	static std::vector<std::string> ConvertArgs(const char* args);

	static std::function<void(std::vector<std::string>)> Create(EventAction action);

	static void AddEvent(EventType type, EventAction action, std::vector<std::string> args);

	static void RemoveEvent(EventType type, EventAction action);

	void Trigger();

	//vector of pair containing the function and args
	std::vector<std::pair<std::function<void(std::vector<std::string>)>, std::vector<std::string>>> Events;

}static TouchApple, TouchFlower;

