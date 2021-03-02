#pragma once
#include "LevelInject.h"
void  __declspec(naked) GetAllObjects()
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
void __declspec(naked) ResetObjects()
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


void __declspec(naked) OnHitKiller()
{
	__asm 
	{
		cmp ecx, 03
		je hitKiller
		jmp LevelInj.jneOnHitKiller
	hitKiller:
		pushad
	}

	//Killer has been hit
	//Stats::stats.killedExitLev();

	__asm {
		popad
		jmp LevelInj.jmpOnHitKiller
	}
}

void __declspec(naked) OnHeadHitFloor()
{
	__asm 
	{
		mov ecx, [ebp + 0x24]
		mov edx, [ebp + 0x20]
		pushad
	}

	//floor has been hit by head
	//Stats::stats.killedExitLev();

	__asm 
	{
		popad
		jmp LevelInj.jmpOnHeadHitFloor
	}
}

void __declspec(naked) OnFlowerFinish()
{
	__asm {
		call LevelInj.callHeadHitFlower
		pushad
	}

	//flower has been hit (and all apples taken)
	//Stats::stats.finishExitLev();

	__asm {
		popad
		jmp LevelInj.jmpOnFlowerFinish
	}
}

void __declspec(naked) getTimeObject()
{

	__asm {
		mov esi, ecx
		mov LevelInj.timeAddrTmp, esi
		xor eax, eax
		push edi
		pushad
	}

	//Level::lev.timeAddress = timeAddrTmp;

	__asm {

		popad
		jmp LevelInj.jmpTimeEnd
	}
}

//Triggers after touching an apple with wheel or head.
void __declspec(naked) OnTouchApple()
{
	__asm { pusha }
	//To update the apple counter
	//draw::dd.statsChanged = true;

	TouchApple.Trigger();

	__asm {
		popa
		mov[eax + 0x2C], 00000000
		jmp LevelInj.touchAppleEnd
	}
}

