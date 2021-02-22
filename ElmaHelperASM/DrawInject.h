#pragma once
#include "Draw.h"

//Draw hook
static int jmpElmaDrawAddr = 0x004955A3;
//Call the original elma function that we removed.
static int callElmaAddr = 0x0041BAF0;


void __declspec() drawInject();