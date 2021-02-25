#pragma once
#include "DrawingObjects.h"

void DrawingText::DrawScreen()
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

void DrawingLine::DrawScreen()
{
	DrawLine(xPos, yPos, xPos2, yPos2, color);
}

void DrawingLine::DrawLine(int x1, int y1, int x2, int y2, int color) 
{
	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if (steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if (x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = y1;

	const int maxX = x2;

	for (int x = x1; x < maxX; x++)
	{
		if (steep)
		{
			DrawPixel(y, x, color);
		}
		else
		{
			DrawPixel(x, y, color);
		}

		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
	}
}

void DrawingArrow::DrawScreen()
{
	double dist;
	double dx;
	double dy;

	dx = xPos2 - xPos;
	dy = yPos2 - yPos;
	int x3 = xPos;
	int y3 = yPos;
	//Get the distance of point A to point B
	dist = std::sqrt(dx * dx + dy * dy);

	/*if (maxLength == -1) maxLength = dist;
	if (minLength == -1) minLength = dist;*/

	//Calculate maximum distance of arrow.
	if (dist > 0)
	{
		dx /= dist;
		dy /= dist;
	}

	/*if (dist > maxLength)
	{
		dx *= maxLength;
		dy *= maxLength;
	}
	else if (dist < minLength)
	{
		dx *= minLength;
		dy *= minLength;
	}
	else
	{*/
		dx *= dist;
		dy *= dist;
	/*}*/
	x3 = (int)(xPos + dx);
	y3 = (int)(yPos + dy);

	double pi = 3.1415926535897931;
	const int r = 20;
	double join_angle = pi / 4.0;
	double stem_angle = std::atan2(yPos2 - yPos, xPos2 - xPos);

	//Draw the line from point A to B
	DrawLine(xPos, yPos, x3, y3, color);

	//Draw arrow
	DrawLine(x3, y3, x3 - int(r * std::cos(stem_angle + join_angle)), y3 - int(r * std::sin(stem_angle + join_angle)), color);
	DrawLine(x3, y3, x3 - int(r * std::cos(stem_angle - join_angle)), y3 - int(r * std::sin(stem_angle - join_angle)), color);
}

void DrawingRect::DrawScreen()
{
	int x = xPos;
	int y = yPos;
	int x2 = xPos2;
	int y2 = yPos2;
	int col = color;
	int surface = *(int*)playingSurf;

	__asm 
	{
		push col
		push y
		push x
		push y2
		push x2
		mov ecx, surface
		call RectFillDrawFunction
	}
}

void DrawingCircle::DrawScreen()
{
	const double pi = 3.1415926535897931;
	const double inc = pi / 12;
	const double max = 2 * pi;

	for (double d = 0; d < max; d += inc) {
		
		DrawLine(cos(d) * rad + xPos, sin(d) * rad + yPos, cos(d - inc) * rad + xPos, sin(d - inc) * rad + yPos, color);
	}
}

void DrawingObjects::DrawPixel(int xPos, int yPos, byte color)
{
	int surface = *(int*)playingSurf;

	__asm
	{
		mov ecx, surface
		push color
		push yPos
		push xPos
		call PixelDrawFunction
	}
}
