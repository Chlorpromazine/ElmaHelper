#pragma once
#include <Windows.h>
#include "DrawingObjects.h"
#include <vector>
#include "Memory.h"
#include <mutex>

class Draw {
private:
	static std::vector<DrawingObjects*> drawObjects;

	
	
	static const int PixelDrawFunction = 0x00429490;

	static std::mutex drawLock;

public:
	static void InitDrawing();

	static void AddObjectToDraw(DrawingObjects* drawObj);

	static void DrawPixel(int x, int y, byte color);

	static void DrawAllObjects();

}static Drawing;