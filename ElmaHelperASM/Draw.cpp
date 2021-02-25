#pragma once
#include "Draw.h"
#include "DrawInject.h"

std::map<std::string, DrawingObjects*> Draw::drawObjects;
std::map<std::string, DrawingObjects*> Draw::drawObjectsBuffer;
std::mutex Draw::drawLock;
bool Draw::updated;

void Draw::InitDrawing() 
{
	//Hook code to add our drawing functions
	Memory.JumpPatch((BYTE*)0x0049559E, (BYTE*)&drawInject, 0);

	updated = false;
}



void Draw::DrawAllObjects()
{
	if (updated) 
	{
		drawLock.lock();
		drawObjects.clear();
		drawObjects = drawObjectsBuffer;
		drawLock.unlock();
		updated = false;
	}
	for (auto &var : drawObjects)
	{
		var.second->DrawScreen();
	}
}


void Draw::AddObjectToDraw(DrawingObjects* drawObj)
{
	drawLock.lock();

	//It will replace the object if it's already in the vector
	if (drawObjectsBuffer.find(drawObj->name) != drawObjectsBuffer.end())
	{
		drawObjectsBuffer[drawObj->name] = drawObj;
	}
	else 
	{
		drawObjectsBuffer.emplace(drawObj->name, drawObj);
	}

	SortObjectsByZorder();

	updated = true;

	drawLock.unlock();
}

void Draw::RemoveDrawObject(std::string name)
{
	drawLock.lock();

	drawObjectsBuffer.erase(name);

	updated = true;

	drawLock.unlock();
}

void Draw::SortObjectsByZorder() 
{
	if (drawObjectsBuffer.size() < 2) return;
	std::vector< DrawingObjects*> tmpDrawingObj;

	for (auto it = drawObjectsBuffer.begin(); it != drawObjectsBuffer.end(); ++it)
	{
		tmpDrawingObj.push_back(it->second);
	}
	
	std::sort(tmpDrawingObj.begin(), tmpDrawingObj.end(), [](DrawingObjects* obj, DrawingObjects* obj2)
	{
		return (obj->zOrder < obj2->zOrder);
	});

	drawObjectsBuffer.clear();

	for (auto obj : tmpDrawingObj) 
	{
		drawObjectsBuffer.emplace(obj->name, obj);
	}
}