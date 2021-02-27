#pragma once
#include "LevelInject.h"
void  __declspec(naked) getAllObjects()
{
	__asm {pusha}

	//cout << "Objects loaded" << endl;

	__asm {
		popa

		fld qword ptr[esi + 8]
		fchs
		mov LevelInj.objAddr, esi
		mov[esi + 0x10], eax
		fsub qword ptr[edi + 0x20]
		pusha
	}

	AddLevelObject(LevelInj.objAddr);


	__asm {
		popa
		jmp LevelInj.jmpGetObjEnd
	}

}

/*
*	Called right before loading a new level.
*	Entering the same level multiple times won't trigger this.
*/
void __declspec(naked) resetObjects()
{
	__asm {pusha}

	//Clear all of the objects for the previous level.
	LevelObjects.allObjects.clear();
	LevelObjects.allObjectsNewProperties.clear();
	//Kuski::kus.enterNewLevel();

	__asm {
		popa
		call LevelInj.callObjStart
		jmp LevelInj.jmpObjEnd
	}
}

void AddLevelObject(int objAddr)
{
	LevelObjects.allObjects.push_back((LevelObject::objStruct*)objAddr);
}