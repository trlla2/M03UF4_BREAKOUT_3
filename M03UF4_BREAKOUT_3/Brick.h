#pragma once
#include "Vector2.h"

class Brick {

private:
	Vector2 position;
	int health;

public:
	Brick(Vector2 p, int h);
	Vector2 GetPosition();
	void SetPosition(Vector2);
	int GetHealth();
	void TakeDamage(int amount);
	void Render();

};