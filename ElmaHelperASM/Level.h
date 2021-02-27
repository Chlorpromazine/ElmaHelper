#pragma once
#include <string>
#include "Memory.h"
#include "LevelInject.h"

class Lvl {
private:
	static const int LevName = 0x00485674;
	int framesPerSecond = 0x00447418;

public:
	Lvl();

	static std::string getLevelName();

}static Level;