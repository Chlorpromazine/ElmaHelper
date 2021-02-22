#pragma once
#include "Draw.h"
#include "DrawInject.h"

std::vector<DrawingObjects*> Draw::drawObjects;
std::mutex Draw::drawLock;

void Draw::InitDrawing() 
{
	//drawObjects = new std::vector<DrawingObjects>();
	//Hook code to add our drawing functions
	Memory.JumpPatch((BYTE*)0x0049559E, (BYTE*)&drawInject, 0);
}

void Draw::DrawPixel(int x, int y, byte color) 
{
	//int surface = *(int*)playingSurf;
	////todo: add error messages
	//if (surface == NULL) return;

	//__asm 
	//{
	//	mov ecx, surface
	//	push color
	//	push y
	//	push x
	//	call PixelDrawFunction
	//}

}

void Draw::DrawAllObjects()
{
	drawLock.lock();
	for (auto &var : drawObjects)
	{
		var->drawScreen();
	}
	drawLock.unlock();
	
}

void Draw::AddObjectToDraw(DrawingObjects* drawObj)
{
	drawLock.lock();
	drawObjects.push_back(drawObj);
	drawLock.unlock();
}

