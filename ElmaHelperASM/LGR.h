#pragma once
#include "Memory.h"
#include "LGRInject.h"
#include <string>

class LGRClass 
{
private:
	static const int LGRNameAddr = 0x0048564C;
	static std::string LGRName;
public:
	static bool LGRchanged;

	LGRClass();

	static void changeLGR();
	static void setLGR(const char* name);

}static LGR;