#pragma once
#include"Brick.h"
#include"Pad.h"
#include"Wall.h"

class Ball {
private:
	int damage;
	Vector2 direcction;

public:
	Vector2 position;
	Ball(Vector2 p, Vector2 dir, int dmg);
	void Bounce(Vector2 normal);
	void Update(Wall walls[], Brick bricks[], Pad pads[] );
	int GetDamage();
	Vector2 GetDirection();
	Vector2 GetPosition();
	void Render();


};