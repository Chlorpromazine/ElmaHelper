#pragma once
#include "LGR.h"

static int jmpChangeLGR = 0x00422DAE;
static int callNewLevel = 0x00445E00;
static int jmpNewLevel = 0x00425870;
static int callNewLGR = 0x00445E00;
static int jmpNewLGR = 0x00422B0B;

void __declspec() changeLGRinject();
void __declspec() changeToNewLevel();
void __declspec() changeToNewLGR();