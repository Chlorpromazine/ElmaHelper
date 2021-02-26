#pragma once
#include "LGRInject.h"

//Placed after getting the LGR name (so we can change it now) and before loading the LGR.
void __declspec(naked) changeLGRinject()
{

	LGR.changeLGR();

	__asm {
		push 0x0000A280
		jmp jmpChangeLGR
	}
}

//Compares to see if the level is the same being played or not.
void __declspec(naked) changeToNewLevel()
{

	__asm {
		call callNewLevel
		pushad
	}

	//Force LGR change
	if (LGR.LGRchanged)
	{
		__asm {
			popad
			mov eax, 1
		}
	}
	else
	{
		__asm {
			popad
		}
	}

	__asm {
		jmp jmpNewLevel
	}
}

//Compares the current LGR with the selected level LGR (only called when changeToNewLevel() is called)
void __declspec(naked) changeToNewLGR()
{

	__asm {
		call callNewLGR
		pushad
	}

	//Force LGR change
	if (LGR.LGRchanged)
	{
		LGR.LGRchanged = false;
		__asm {
			popad
			mov eax, 1
		}
	}
	else
	{
		__asm {
			popad
		}
	}

	__asm {
		jmp jmpNewLGR
	}
}
