#pragma once
#include "Vector2.h"
#include "ConsoleControl.h"

class Brick {

private:
	Vector2 position;
	int health;

public:
	Brick(Vector2 p, int h)
		:position(p), health(h) {}
	Vector2 GetPosition() { return position; }
	void SetPosition(Vector2 p) { position = p; }
	int GetHealth() { return health; }
	void TakeDamage(int dmg) { health -= dmg; }
	void Render() {
		ConsoleXY(position.x, position.y);
		std::cout << "#";
	}

};