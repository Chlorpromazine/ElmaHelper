#pragma once
#include <Windows.h>

class Mem 
{
private:
	
public:
	static void CallPatch(BYTE* Dest, BYTE* Src, int Nops);
	static void JumpPatch(BYTE* Dest, BYTE* Src, int Nops);

	static void MemPatch(BYTE* Dest, BYTE* Src, int Len);

	template<typename T>
	static void MemPatchTemplate(BYTE* dest, T src, int len = 0) 
	{
		DWORD Old;

		if (len == 0) {
			len = sizeof(T);
		}
		
		VirtualProtect(dest, len, PAGE_EXECUTE_READWRITE, &Old);
		memcpy(dest, &src, len);
		VirtualProtect(dest, len, Old, &Old);
	}
}static Memory;