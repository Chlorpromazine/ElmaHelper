#pragma once

#include "DllExports.h"
#include "Memory.h"
#include "Draw.h"

extern "C" 
{
#pragma region
	void dllexp ModifyMemValue(int address, BYTE* value, int size)
	{
		for (int i = 0; i < size; i++) 
		{
			Memory.MemPatchTemplate((BYTE*)address + i, value[i]);
		}
	}

	void dllexp AddJump(int destAddr, int srcAddr, int nops = 0)
	{
		Memory.JumpPatch((BYTE*)destAddr, (BYTE*)srcAddr, nops);
	}

	void dllexp AddCall(int destAddr, int srcAddr, int nops = 0)
	{
		Memory.CallPatch((BYTE*)destAddr, (BYTE*)srcAddr, nops);
	}
#pragma endregion Memory

#pragma region
	void dllexp InitDrawing() 
	{
		Drawing.InitDrawing();
	}

	void dllexp DrawPixel(int x, int y, BYTE color)
	{
		Drawing.DrawPixel(x, y, color);
	}
	
	/*void dllexp DrawObject(DrawingObjects* drawObj)
	{
		Drawing.AddObjectToDraw(drawObj);
	}*/

	void dllexp DrawTxt(const char* text, const char* name, const char* parentName, int x, int y, int zOrder, bool visible, int spaceBetweenChars) 
	{
		auto drawObj = new DrawingText();
		drawObj->text = text;
		drawObj->name = name;
		drawObj->parentName = parentName;
		drawObj->xPos = x;
		drawObj->yPos = y;
		drawObj->zOrder = zOrder;
		drawObj->visible = visible;
		drawObj->spaceBetweenChars = spaceBetweenChars;

		Drawing.AddObjectToDraw(drawObj);
	}

#pragma endregion Drawing
}