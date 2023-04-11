#pragma once
#include <iostream>
#include "ConsoleControl.h"
#include "Vector2.h"
enum WallType { HORIZONTAL, VERTICAL, CORNER };


class Wall {

private:
	Vector2 position;
	WallType type;
	int width;

public:
	Wall(WallType t, Vector2 p)
		: type(t), position(p) {}
	Vector2 GetPosition() { return position; }
	WallType GetType() { return type; }
	void Render();
	int GetWidth() { return width; }


};

