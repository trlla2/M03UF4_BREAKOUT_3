#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad) {
    Vector2 targetPos = position + direction;

    for (auto it = walls.begin(); it != walls.end(); it++) {
        if (it->GetPosition() == targetPos) {
           
            switch (it->GetType()) {
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
            Vector2 bP = it->GetPosition();
            Brick bS;//poner constructor
            if (direction.x = 0) {
                direction.y *= -1;
            }
            else if (position.x + direction.x == bP.x -1 ) {
                Vector2 bPS = it->GetPosition();
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    bS = *itS;
                    bPS = bS.GetPosition();
                    if (bPS.x == bP.x - 1) {
                        break;//breack for
                    }
                }
            }
            else if (position.x + direction.x == bP.x + 1) {
                Vector2 bPS = it->GetPosition();
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    bS = *itS;
                    bPS = bS.GetPosition();
                    if (bPS.x == bP.x - 1) {
                        break;
                    }
                }
            }
            else
            {
                direction.x *= -1;
                direction.y *= -1;
            }
        
        
            
        
            it->TakeDamage(GetDamage());
        }
    }

 
    Vector2 padPos = pad->GetPosition();
    int padWidth = pad->GetWidth();
    if (targetPos.y == padPos.y - 1 && targetPos.x >= padPos.x && targetPos.x <= padPos.x + padWidth - 1) {
       
        float sectionWidth = (float)padWidth / 3.0f;
        float ballX = targetPos.x - padPos.x;
        float section = std::floor(ballX / sectionWidth);

        
        switch ((int)section) {
        case 0:
            direction.x = -1;
            direction.y = -1;
            break; 
        case 1:
            direction.x = 0;
            direction.y = -1;
            break; 
        case 2:
            direction.x = 1;
            direction.y = -1;
            break; 
        default:
            direction.x = 0;
            direction.y = -1;
            break;
        }
    }

    if (targetPos.y >= walls.back().GetPosition().y) {
        
        position = Vector2(25 / 2, 15 / 2);
        direction.x = 0;
        direction.y = 1;
    }
    else {
        position = position + direction;
    }
}




