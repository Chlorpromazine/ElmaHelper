#include "Events.h"

std::map<std::string, std::function<void(std::vector<std::string>)>> Events::functionList =
{
	{"SetLGR", SetLGR},
	{"SetAcceleration", SetAcceleration}
};

void Events::SetLGR(const std::vector<std::string>& name)
{
	LGR.SetLGR(name[0].c_str());
}

void Events::SetAcceleration(const std::vector<std::string>& name)
{
	Kuski.SetAcceleration(std::stod(name[0]));
}

std::function<void(std::vector<std::string>)> Events::getFunction(std::string funcStr)
{
	if (functionList.count(funcStr) != 0)
		return functionList[funcStr];
	return NULL;
}
