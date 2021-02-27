#include "LevelObjects.h"

LevelObject::LevelObject() {

	//object currently selected
	curObject = 0;

}

//unused
/*
*	Changes the selected object to the next value.
*	1 = flower, 2 = apple, 3 = killer, 4 = start (only 1 start location or it crashes)
*	Values other than those crashes the game.
*/
void LevelObject::changeObject(int curObj)
{
	if (allObjects.size() > curObj)
	{
		//read current object type;
		BYTE* Dest = (BYTE*)(allObjects[curObject]->type);
		BYTE type = *(BYTE*)Dest;

		type++;
		if (type > 4) type = 1;

		BYTE Buff[1] = { type };
		Memory.MemPatch(Dest, Buff, 1);

	}
}

/*
*	Changes the activation flag of selected object.
*	Apples will become visible or invisible when toggled.
*	Start object does nothing.
*	Killers and flowers will always show but the collision can be removed if toggled off.
*/
void LevelObject::objectActive(int curObj, bool active)
{
	if (allObjects.size() > curObj)
	{
		//read current object type;
		BYTE* Dest = (BYTE*)(allObjects[curObj]->active);
		BYTE type = *(BYTE*)Dest;

		//1 active, 0 non active
		type = active;

		BYTE Buff[1] = { type };
		Memory.MemPatch(Dest, Buff, 1);

	}
}




/*
*	Selects the next object in the array to be modified.
*/
void LevelObject::nextObject()
{
	if (allObjects.size())
	{
		//The last object is always null, remove it.
		if (curObject < allObjects.size() - 1)
			curObject++;
		else
			curObject = 0;
	}
}

/*
*	Moves the selected object to another position using the arrow keys.
*/
void LevelObject::moveObject(int dir)
{
	if (allObjects.size())
	{
		pos position = getLocation();

		switch (dir) {
		case 0: //Up
			position.y++;
			break;
		case 1: //Down
			position.y--;
			break;
		case 2: //Left
			position.x--;
			break;
		case 3: //Right
			position.x++;
			break;
		}

		newLocation(position);
	}
}

/*
*	Gets the X/Y location of the selected object.
*/
LevelObject::pos LevelObject::getLocation()
{
	pos position;

	//take the current position from the memory
	position.x = allObjects[curObject]->x;
	position.y = allObjects[curObject]->y;

	return position;
}

/*
*	Gets the X/Y location of a choosen object.
*/
LevelObject::pos LevelObject::getLocation(int obj)
{
	pos position;

	//take the current position from the memory
	position.x = allObjects[obj]->x;
	position.y = allObjects[obj]->y;

	return position;
}
/*
*	Sets the X/Y location of the selected object.
*/
void LevelObject::newLocation(pos newPos)
{
	//copy object location x
	allObjects[curObject]->x = newPos.x;

	//copy object location y
	allObjects[curObject]->y = newPos.y;

}
