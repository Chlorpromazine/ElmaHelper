#pragma once
#include <Windows.h>
#include "DrawingObjects.h"
#include <vector>
#include "Memory.h"
#include <mutex>
#include <algorithm>
#include <map>

class Draw {
private:
	static std::map<std::string, DrawingObjects*> drawObjects;
	static std::map<std::string, DrawingObjects*> drawObjectsBuffer;

	static std::mutex drawLock;

	static const int PixelDrawFunction = 0x00429490;

public:
	static void InitDrawing();

	static void AddObjectToDraw(DrawingObjects* drawObj);

	static void RemoveDrawObject(std::string name);

	static void SortObjectsByZorder();

	static void DrawPixel(int x, int y, byte color);

	static void DrawAllObjects();

}static Drawing;