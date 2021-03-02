#include "EventHandler.h"

//var argStrList = new List<string>();
//
//foreach(var arg in args)
//{
//	argStrList.Add(arg.GetType().ToString().Replace("System.", "") + ":" + arg.ToString());
//}
//var argStr = string.Join("|", argStrList);
//
//DllImports.AddEventHandler(type, trigger, argStr);

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
		std::bind(&LGR.setLGR, func, "Army");
		break;
	case EventAction::dosomethingelse:
		break;
	}
	return func;
}

void EventHandler::AddEvent(EventType type, EventAction action, std::vector<std::string> args)
{
	auto functionAction = Create(action);

	auto functionPair = std::make_pair(functionAction, args);

	switch (type) 
	{
	case EventType::touchApple:
		TouchApple.Events.push_back(functionPair);
		break;
	case EventType::touchFlower:
		break;
	}
}

void EventHandler::RemoveEvent(EventType type, EventAction action)
{

}

void EventHandler::Trigger()
{
	for (auto Event : Events) 
	{
		Event.first(Event.second);
	}
}
