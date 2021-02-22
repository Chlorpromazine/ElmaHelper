#pragma once
#include "DrawInject.h"

//Placed right after Milagros' drawing function so we draw last (on top of everything else)
void __declspec(naked) drawInject()
{

	Drawing.DrawAllObjects();
	/*Objects::obj.displayObjectNumbers();
	Objects::obj.displayObjectArrow();

	Kuski::kus.saveCurrentRide();
	Kuski::kus.shadowKuski();*/

	__asm {

		//Call the function that we replaced and jump back to elma code once we're done.
		call callElmaAddr
		jmp jmpElmaDrawAddr
	}

}
