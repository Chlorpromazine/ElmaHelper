#pragma once
#include <windows.h>
#include <string>

class DrawingObjects
{
protected:
	static const int PixelDrawFunction = 0x00429490;
	static const int playingSurf = 0x00454140;
	static const int fontText = 0x00499164;
	static const int TextDrawFunction = 0x00401340;
	static const int RectFillDrawFunction = 0x00429580;

public:
	const char* name;
	const char* parentName;
	int x;
	int y;
	int zOrder;
	bool visible;
	
	virtual void drawScreen() = 0;

};

class DrawingText : public DrawingObjects
{
public:
	int spaceBetweenChars = -1000; //default
	std::string text;

	void drawScreen();
};

class DrawingLine : public DrawingObjects
{
public:
	int x2;
	int y2;
	double maxLength;
	double minLength;
	BYTE color;

	void drawScreen();
};

class DrawingLineArrow : public DrawingObjects
{
public:
	int x2;
	int y2;
	double maxLength;
	double minLength;
	BYTE color;

	void drawScreen();
};

class DrawingRect : public DrawingObjects
{
public:
	int x2;
	int y2;
	BYTE color;

	void drawScreen();
};

class DrawingCircle : public DrawingObjects
{
public:
	int rad;
	BYTE color;

	void drawScreen();
};


