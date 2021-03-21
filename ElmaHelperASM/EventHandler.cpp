#include "EventHandler.h"

std::vector<EventHandler::eventStruct> EventHandler::Events;

std::vector<std::string> EventHandler::ConvertArgs(const char* args)
{
	return Common::split(std::string(args), '|');
}


std::function<void(std::vector<std::string>)> EventHandler::Create(std::string action)
{
	std::function<void(std::vector<std::string>)> func;

	func = std::bind(Events::getFunction(action), std::placeholders::_1);

	return func;
}

void EventHandler::AddEvent(TriggerType type, std::string action, std::vector<std::string> args)
{
	auto functionAction = Create(action);

	auto functionPair = eventStruct(type, functionAction, args);

	Events.push_back(functionPair);
}

void EventHandler::RemoveEvent(TriggerType type, std::string action)
{

}

void EventHandler::Trigger(TriggerType type)
{
	for (auto Event : Events) 
	{
		if(type == Event.type)
			Event.func(Event.args);
	}
}
