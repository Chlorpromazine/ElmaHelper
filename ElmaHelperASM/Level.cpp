#pragma once
#include "Level.h"

Lvl::Lvl() 
{
	//Get all the objects in the current level
	Memory.JumpPatch((BYTE*)0x00408DEF, (BYTE*)&GetAllObjects, 0);
	Memory.JumpPatch((BYTE*)0x00425A7A, (BYTE*)&ResetObjects, 0);

	//When bike hits a killer
	Memory.JumpPatch((BYTE*)0x0041FD50, (BYTE*)&OnHitKiller, 0);

	//When head hits floor
	Memory.JumpPatch((BYTE*)0x0041F9A8, (BYTE*)&OnHeadHitFloor, 0);

	//When level is finished (hit flower with all apples)
	Memory.JumpPatch((BYTE*)0x0041FC82, (BYTE*)&OnFlowerFinish, 0);

	//When any part of the physical bike touches an apple (even if the apple is gone)
	Memory.JumpPatch((BYTE*)0x0041FD62, (BYTE*)&OnTouchApple, 0);
}

//Gets the current level name, works in replay.
std::string Lvl::getLevelName()
{
	//Can't convert to string directly?
	return (std::string)(char*)LevName;
}
