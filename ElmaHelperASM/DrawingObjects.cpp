#pragma once
#include "DrawingObjects.h"

void DrawingText::drawScreen()
{
	if (text == "") return;

	const char* cText = text.c_str();
	int font = *(int*)fontText;
	int surface = *(int*)playingSurf;

	__asm 
	{
		push -1000 //todo: why does -1000 work but putting an int variable with -1000 doesn't work?
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

