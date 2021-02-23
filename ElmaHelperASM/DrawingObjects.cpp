#pragma once
#include "DrawingObjects.h"

void DrawingText::drawScreen()
{
	if (text == "") return;

	const char* cText = text.c_str();
	int font = *(int*)fontText;
	int surface = *(int*)playingSurf;
	int x = xPos;
	int y = yPos;
	int charSpace = spaceBetweenChars;

	__asm 
	{
		push charSpace 
		push cText
		push y
		push x
		mov eax, surface
		push eax
		mov ecx, font
		call TextDrawFunction
	}
}

void DrawingLine::drawScreen()
{

}

void DrawingLineArrow::drawScreen()
{

}

void DrawingRect::drawScreen()
{

}

void DrawingCircle::drawScreen()
{

}

