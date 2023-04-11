#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick> &bricks, Pad* pads) {
	
	Vector2 targetPos = position + direcction;

	for (auto it = walls.begin(); it != walls.end(); it++) {
		if (it->GetPosition() == targetPos) {
			switch (it->GetType())
			{
			case VERTICAL:
				direcction.x *= -1;
				break;
			case HORIZONTAL:
				direcction.y *= -1;

				break;
			case CORNER:
				direcction.x *= -1;
				direcction.y *= -1;
				break;
			}
		}
	}
	for (auto it = bricks.begin(); it != bricks.end(); it++) {
		if (it->GetPosition() == targetPos && it->GetHealth() != 0) {
			it->TakeDamage(GetDamage());

			direcction.y *= -1;
			
		}
	}
	position = position + direcction;

}