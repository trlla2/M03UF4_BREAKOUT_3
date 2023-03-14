#pragma once
#include "Vector2.h"
enum WallType { HORIZONTAL, VERTICAL, CORNER };


class Wall {

private:
	Vector2 position;
	WallType type;

public:
	Wall(WallType t, Vector2 p);
	Vector2 GetPosition();
	WallType GetType();
	void Render();



};