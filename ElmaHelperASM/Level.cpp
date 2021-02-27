#pragma once
#include "Level.h"

Lvl::Lvl() 
{
	Memory.JumpPatch((BYTE*)0x00408DEF, (BYTE*)&getAllObjects, 0);
	Memory.JumpPatch((BYTE*)0x00425A7A, (BYTE*)&resetObjects, 0);
}

//Gets the current level name, works in replay.
std::string Lvl::getLevelName()
{
	//Can't convert to string directly?
	return (std::string)(char*)LevName;
}
