#include "DllExports.h"
#include "Memory.h"


extern "C"
{
	void dllexp ModifyMemValue(int address, unsigned int value)
	{
		MemPatchInt((BYTE*)address, &value);
	}
}