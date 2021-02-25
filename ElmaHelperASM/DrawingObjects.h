#pragma once
#include <windows.h>
#include <string>
#include <cmath>

class DrawingObjects
{
protected:
	static const int PixelDrawFunction = 0x00429490;
	static const int playingSurf = 0x00454140;
	static const int fontText = 0x00499164;
	static const int TextDrawFunction = 0x00401340;
	static const int RectFillDrawFunction = 0x00429580;

public:
	std::string name;
	std::string parentName;
	int xPos;
	int yPos;
	int zOrder;
	bool visible;
	
	virtual void DrawScreen() = 0;

	void DrawPixel(int xPos, int yPos, byte color);

};

class DrawingText : public DrawingObjects
{
public:
	int spaceBetweenChars = -1000;
	std::string text;

	void DrawScreen();
};

class DrawingLine : public DrawingObjects
{
public:
	int xPos2;
	int yPos2;
	BYTE color;

	void DrawScreen();
	void DrawLine(int x1, int y1, int x2, int y2, int color);
};

class DrawingArrow : public DrawingLine
{
public:
	void DrawScreen();
};

class DrawingRect : public DrawingObjects
{
public:
	int xPos2;
	int yPos2;
	BYTE color;

	void DrawScreen();
};

class DrawingCircle : public DrawingLine
{
public:
	int rad;
	BYTE color;

	void DrawScreen();
};


