#pragma once
#include "DllExports.h"

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

	void dllexp DrawLine(const char* name, const char* parentName, int x, int y, int x2, int y2, int color, int zOrder, bool visible, bool arrow)
	{
		auto drawObj = new DrawingLine();
		if(arrow) drawObj = new DrawingArrow();
		drawObj->name = name;
		drawObj->parentName = parentName;
		drawObj->xPos = x;
		drawObj->yPos = y;
		drawObj->xPos2 = x2;
		drawObj->yPos2 = y2;
		drawObj->color = color;
		drawObj->zOrder = zOrder;
		drawObj->visible = visible;

		Drawing.AddObjectToDraw(drawObj);
	}
	
	void dllexp DrawCircle(const char* name, const char* parentName, int x, int y, int rad, int color, int zOrder, bool visible)
	{
		auto drawObj = new DrawingCircle();
		drawObj->name = name;
		drawObj->parentName = parentName;
		drawObj->xPos = x;
		drawObj->yPos = y;
		drawObj->rad = rad;
		drawObj->color = color;
		drawObj->zOrder = zOrder;
		drawObj->visible = visible;

		Drawing.AddObjectToDraw(drawObj);
	}

	void dllexp DrawRect(const char* name, const char* parentName, int x, int y, int x2, int y2, int color, int zOrder, bool visible)
	{
		auto drawObj = new DrawingRect();
		drawObj->name = name;
		drawObj->parentName = parentName;
		drawObj->xPos = x;
		drawObj->yPos = y;
		drawObj->xPos2 = x2;
		drawObj->yPos2 = y2;
		drawObj->color = color;
		drawObj->zOrder = zOrder;
		drawObj->visible = visible;

		Drawing.AddObjectToDraw(drawObj);
	}

	void dllexp RemoveDrawObject(const char* name) 
	{
		Drawing.RemoveDrawObject(name);
	}

#pragma endregion Drawing

#pragma region

	void dllexp LoadLGR(const char* name)
	{
		LGR.setLGR(name);
	}

#pragma endregion LGR
}