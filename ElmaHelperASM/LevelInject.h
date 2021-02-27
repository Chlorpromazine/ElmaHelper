#pragma once
#include "LevelObjects.h"

class LevelInject
{
public:
	const int jmpGetObjEnd = 0x00408DFA;
	int objAddr;
	const int callObjStart = 0x0040AEF0;
	const int jmpObjEnd = 0x00425A7F;

}static LevelInj;





void  __declspec() getAllObjects();
void __declspec() resetObjects();
void AddLevelObject(int objAddr);