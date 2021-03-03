#pragma once
#include "LevelObjects.h"
#include "EventHandler.h"

class LevelInject
{
public:
	const int jmpGetObjEnd = 0x00408DFA;
	int objAddr;
	const int callObjStart = 0x0040AEF0;
	const int jmpObjEnd = 0x00425A7F;

	//When the bike hits a killer
	const int jmpOnHitKiller = 0x0041FD55;
	const int jneOnHitKiller = 0x0041FD59;

	//When head hits floor
	const int jmpOnHeadHitFloor = 0x0041F9AE;

	//When player finishes level (hits flower with all apples collected)
	const int callHeadHitFlower = 0x0043CB4C;
	const int jmpOnFlowerFinish = 0x0041FC87;

	//time object
	const int jmpTimeEnd = 0x0042D5B3;
	int timeAddrTmp;

	//When player touches apple
	const int touchAppleEnd = 0x0041FD69;



}static LevelInj;

void testTrigger();
void  __declspec() GetAllObjects();
void __declspec() ResetObjects();
void __declspec() OnHitKiller();
void __declspec() OnHeadHitFloor();
void __declspec() OnFlowerFinish();
void __declspec() OnTouchApple();
void __declspec() getTimeObject();

void AddLevelObject(int objAddr);
