#pragma once
#include "LGR.h"
bool LGRClass::LGRchanged = true;
std::string LGRClass::LGRName;

void LGRClass::InitLGR() 
{
	//Force change LGR
	Mem::JumpPatch((BYTE*)0x00422DA9, (BYTE*)&changeLGRinject, 0);
	Mem::JumpPatch((BYTE*)0x0042586B, (BYTE*)&changeToNewLevel, 0);
	Mem::JumpPatch((BYTE*)0x00422B06, (BYTE*)&changeToNewLGR, 0);
}

void LGRClass::changeLGR()
{
	if(LGRName.length() != 0)
		strcpy((char*)LGRNameAddr, LGRName.c_str());

		//strcpy_s((char*)LGRNameAddr, strlen(LGRName), LGRName);
}

void LGRClass::setLGR(const char* name)
{
	LGRchanged = true;
	LGRName = std::string(name);
}
