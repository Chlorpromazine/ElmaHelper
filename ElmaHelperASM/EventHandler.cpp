#include "EventHandler.h"

std::vector<EventHandler::eventStruct> EventHandler::Events;

std::vector<std::string> EventHandler::ConvertArgs(const char* args)
{
	return Generic::split(std::string(args), '|');
}


std::function<void(std::vector<std::string>)> EventHandler::Create(EventAction action)
{

	std::function<void(std::vector<std::string>)> func;

	switch (action) 
	{
	case EventAction::dosomething:
		func = std::bind(Events::setLGR, std::placeholders::_1);
		//std::bind(LGR.setLGR, func, std::placeholders::_1);
		//std::function<int(int)> bar = std::bind(LGR.setLGR, 2, std::placeholders::_1);
		break;
	case EventAction::dosomethingelse:
		break;
	}
	return func;
}

void EventHandler::AddEvent(EventType type, EventAction action, std::vector<std::string> args)
{
	auto functionAction = Create(action);

	auto functionPair = eventStruct(type, functionAction, args);

	switch (type) 
	{
	case EventType::touchApple:
		Events.push_back(functionPair);
		break;
	case EventType::touchFlower:
		break;
	}
}

void EventHandler::RemoveEvent(EventType type, EventAction action)
{

}

void EventHandler::Trigger(EventType type)
{
	for (auto Event : Events) 
	{
		if(type == Event.type)
			Event.func(Event.args);
	}
}
