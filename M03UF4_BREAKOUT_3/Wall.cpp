#include "Wall.h"

void Wall::Render()
{
	ConsoleXY(position.x, position.y);

	switch (type)
	{
	case HORIZONTAL:
		std::cout << "-";
		break;
	case VERTICAL:
		std::cout << "|";
		break;
	case CORNER:
		std::cout << "=";
		break;
	default:
		break;
	}

}