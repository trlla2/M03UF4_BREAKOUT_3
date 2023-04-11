#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick> bricks, Pad* pads) {
	
	Vector2 targetPos = position + direcction;

	for (auto it = walls.begin(); it != walls.end(); it++) {
		if (it->GetPosition() == position) {
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
	for (auto it = bricks.begin(); it != walls.end(); it++) {
		if (it->GetPosition() == position && it->GetHealth() != 0) {
				direcction.x *= -1;
		}
	}
	position = position + direcction;

}