#pragma once
#include "ConsoleControl.h"
#include "Wall.h"
#include "Vector2.h"

class Pad {
private:
	Vector2 position;
	int width;
public:

	Pad(Vector2 p, int w)
		: position(p), width(w) {}
	int GetWidth();
	void SetWidth(int w);
	void Update(Wall walls[]);
	void SetPosition(Vector2 pos);
	void Render();
}; 