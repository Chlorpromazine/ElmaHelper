#pragma once
#include <vector>
#include <string>
#include "LGR.h"
#include "Kuski.h"
#include <map>
#include <functional>

class Events
{
private:
	static std::map<std::string, std::function<void(std::vector<std::string>)>> functionList;

public:
	static void SetLGR(const std::vector<std::string>& name);

	static void SetAcceleration(const std::vector<std::string>& name);

	static std::function<void(std::vector<std::string>)> getFunction(std::string funcStr);
	
};

