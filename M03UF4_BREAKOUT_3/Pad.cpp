#include "Pad.h"





void Pad::Render() {
	//Moure el cursor a la posicio
	ConsoleXY(position.x, position.y);

	//Canviar el color
	ConsoleSetColor(ConsoleColor::DARKMAGENTA, ConsoleColor::BLACK);
		//Dibuixar la pala
		std::cout << "-";



}