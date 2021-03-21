#pragma once
#include "LGR.h"
bool LGRClass::LGRchanged = true;
std::string LGRClass::LGRName;

LGRClass::LGRClass()
{
	//Force change LGR
	Mem::JumpPatch((BYTE*)0x00422DA9, (BYTE*)&changeLGRinject, 0);
	Mem::JumpPatch((BYTE*)0x0042586B, (BYTE*)&changeToNewLevel, 0);
	Mem::JumpPatch((BYTE*)0x00422B06, (BYTE*)&changeToNewLGR, 0);
}

void LGRClass::changeLGR()
{
	if(LGRName.length() != 0)
		strcpy_s((char*)LGRNameAddr, LGRName.length() + 1, LGRName.c_str());
}


void LGRClass::SetLGR(const char* name)
{
	LGRchanged = true;
	LGRName = std::string(name);
}
