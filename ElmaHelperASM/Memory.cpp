#pragma once
#include "Memory.h"

//Stolen from Starcraft hacks and changed around a bit
//These will just set the page to read/write/execute and will help add Calls and Jumps.
void Mem::CallPatch(BYTE* Dest, BYTE* Src, int Nops) {
	BYTE Buff[100];
	Buff[0] = 0xE8;
	*(int*)&Buff[1] = Src - (Dest + 5);

	for (int i = 5; i < Nops + 5; i++) {
		Buff[i] = 0x90;
	}
	MemPatch(Dest, Buff, Nops + 5);
}

void Mem::JumpPatch(BYTE* Dest, BYTE* Src, int Nops) {
	BYTE Buff[100];
	Buff[0] = 0xE9;
	*(int*)&Buff[1] = Src - (Dest + 5);

	for (int i = 5; i < Nops + 5; i++) {
		Buff[i] = 0x90;
	}

	MemPatch(Dest, Buff, Nops + 5);
}

void Mem::MemPatch(BYTE* Dest, BYTE* Src, int Len) {
	DWORD Old;

	VirtualProtect(Dest, Len, PAGE_EXECUTE_READWRITE, &Old);
	memcpy(Dest, Src, Len);
	VirtualProtect(Dest, Len, Old, &Old);
}