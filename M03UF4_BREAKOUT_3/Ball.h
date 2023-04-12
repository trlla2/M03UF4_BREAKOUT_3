#pragma once
#include <vector>
#include"Brick.h"
#include"Pad.h"
#include"Wall.h"
#include "Vector2.h"
class Ball {
private:
	int damage;
	Vector2 direction;
	Vector2 position;

public:
	Ball(Vector2 p, Vector2 dir, int dmg)
		:position(p), direction(dir), damage(dmg) {}

	void SetDirection(Vector2 dir) {
		direction = dir;
	}

	void Bounce(Pad* pad);
	void Update(std::vector<Wall> walls, std::vector<Brick> &bricks, Pad* pads);
	int GetDamage() { return damage; }
	Vector2 GetDirection();
	Vector2 GetPosition();
	void Render() {
		ConsoleXY(position.x, position.y);
		std::cout << "@";
	}


};

	


