#pragma once
#include <Windows.h>

void MemPatch(BYTE* Dest, BYTE* Src, int Len);
void MemPatchInt(BYTE* Dest, unsigned int* Src, int Len);
void CallPatch(BYTE* Dest, BYTE* Src, int Nops);
void JumpPatch(BYTE* Dest, BYTE* Src, int Nops);