#pragma once

#define dllexp __declspec(dllexport)

void dllexp ModifyMemValue(int address, unsigned int value);
