#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pads) {

	Vector2 targetPos = position + direction;

	for (auto it = walls.begin(); it != walls.end(); it++) {
		if (it->GetPosition() == targetPos) {
			switch (it->GetType())
			{
			case VERTICAL:
				direction.x *= -1;
				break;
			case HORIZONTAL:
				direction.y *= -1;

				break;
			case CORNER:
				direction.x *= -1;
				direction.y *= -1;
				break;
			}
		}
	}
	for (auto it = bricks.begin(); it != bricks.end(); it++) {
		if (it->GetPosition() == targetPos && it->GetHealth() != 0) {
			it->TakeDamage(GetDamage());

			direction.y *= -1;

		}
	}
	position = position + direction;

}