#pragma once
#include "Memory.h"

class Kuski
{
private:
	static const int rightWheelAccel = 0x00420D17;
	static const int leftWheelAccel = 0x00420CF2;
public:
	static void SetAcceleration(double speed);

	static void SetAccelerationWheel(BYTE* speed, int wheel);


	static void AddAcceleration(double speed);

	static int GetAcceleration(int wheel);


}static Kuski;

