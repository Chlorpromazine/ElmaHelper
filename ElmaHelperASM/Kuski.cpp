#include "Kuski.h"

void Kuski::SetAcceleration(double speed)
{
	//Going too fast will just crash
	if (speed > 3000) speed = 3000;
	else if (speed < 0) speed = 0;

	double negSpeed = -speed;

	BYTE* rightWheelSpeed = (BYTE*)((int)&speed + 0x04);
	BYTE* leftWheelSpeed = (BYTE*)((int)&(negSpeed) + 0x04);

	SetAccelerationWheel(rightWheelSpeed, rightWheelAccel);
	SetAccelerationWheel(leftWheelSpeed, leftWheelAccel);

}

void Kuski::SetAccelerationWheel(BYTE* speed, int wheel)
{
	Memory.MemPatch((BYTE*)wheel, speed, 4);
}

void Kuski::AddAcceleration(double speed)
{
	int accel = GetAcceleration(rightWheelAccel);

	SetAcceleration(accel + speed);
}

int Kuski::GetAcceleration(int wheel) 
{
	return *&wheel;
}