#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad, int brokenBlocks) {
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


    bool hitBrick = false;
    //Aquest bucle for sustitueix el buqule de abaix que fa les comprovacions ja que dona un error
    for (auto& brick : bricks) {
        if (brick.GetHealth() == 0) {
            continue; // skip broken bricks
        }
        if (brick.GetPosition() == targetPos) {
            brick.TakeDamage(GetDamage());
            direction.y *= -1;
            hitBrick = true;
            brokenBlocks++;
            score += 15 + 5 * (brokenBlocks - 1);
            break;
        }
    }

    if (!hitBrick) {
        brokenBlocks = 0; // reset broken blocks count if ball misses a brick
    }

    //Peta dona un Debug Assertion Failed i no entenc perque
    for (auto it = bricks.begin(); it != bricks.end(); it++) {
        if (it->GetPosition() == targetPos && it->GetHealth() != 0) {
            Vector2 brickPosition = it->GetPosition();
            Brick brickSide = *it;
            Brick brickUp = *it;
            if (direction.x = 0) {
                direction.y *= -1;
            }
            else if (position.x + direction.x == brickPosition.x - 1) {
                Vector2 brickSidePosition = it->GetPosition();
                Vector2 brickUpPosition = it->GetPosition();
                //comprovacio del brick del side
                bool isDeadBSide = true;
                bool isDeadBUp = true;
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    brickSide = *itS;
                    brickSidePosition = brickSide.GetPosition();
                    if (brickSidePosition.x == brickPosition.x + 1 && brickSide.GetHealth() != 0) {
                        isDeadBSide = false;
                        break;
                    }

                }
                //comprovacio del brick de adalt
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    brickUp = *itS;
                    brickUpPosition = brickUp.GetPosition();
                    if (brickUpPosition.y == brickPosition.y - 1 && brickUp.GetHealth() != 0) {
                        isDeadBUp = false;
                        break;
                    }

                }
                //destruir els bricks si no estan morts
                if (isDeadBSide == false)
                    brickSide.TakeDamage(GetDamage());
                if (isDeadBUp == false)
                    brickUp.TakeDamage(GetDamage());
                //desvio la direccio
                direction.x *= -1;
                direction.y *= -1;
            }
            else if (position.x + direction.x == brickPosition.x + 1) {
                Vector2 brickSidePosition = it->GetPosition();
                Vector2 brickUpPosition = it->GetPosition();
                //comprovacio del brick del side
                bool isDeadBSide = true;
                bool isDeadBUp = true;
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    brickSide = *itS;
                    brickSidePosition = brickSide.GetPosition();
                    if (brickSidePosition.x == brickPosition.x - 1 && brickSide.GetHealth() != 0) {
                        isDeadBSide = false;
                        break;
                    }

                }
                //comprovacio del brick de adalt
                for (auto itS = bricks.begin(); it != bricks.end(); it++) {
                    brickUp = *itS;
                    brickUpPosition = brickUp.GetPosition();
                    if (brickUpPosition.y == brickPosition.y - 1 && brickUp.GetHealth() != 0) {
                        isDeadBUp = false;
                        break;
                    }

                }
                //destruir els bricks si no estan morts
                if (isDeadBSide == false)
                    brickSide.TakeDamage(GetDamage());
                if (isDeadBUp == false)
                    brickUp.TakeDamage(GetDamage());
                //desvio la direccio
                direction.x *= -1;
                direction.y *= -1;
            }
            else
            {
                direction.x *= -1;
                direction.y *= -1;
            }




            it->TakeDamage(GetDamage());
            direction.y *= -1;
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
        score += 5;
    }

    if (targetPos.y >= walls.back().GetPosition().y) {
        if (lives <= 0) {

        }

        position = Vector2(25 / 2, 15 / 2);
        direction.x = 0;
        direction.y = 1;
        lives--;
    }
    else {
        position = position + direction;
    }
}

void saveScore(int score) {

    std::string playerName;
    std::cout << "Enter player name: ";
    std::cin >> playerName;

    std::ofstream outFile("scores.bin", std::ios::binary | std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening scores file" << std::endl;
        return;
    }

    outFile.write(playerName.c_str(), playerName.length() + 1);
    outFile.write(reinterpret_cast<const char*>(&score), sizeof(score));

    outFile.close();
}


void loadScores() {
    std::ifstream inFile("scores.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening scores file" << std::endl;
        return;
    }

    std::string playerName;
    int score;

    std::cout << "Scores:" << std::endl;
    while (inFile.read(reinterpret_cast<char*>(&playerName), sizeof(playerName))) {
        inFile.read(reinterpret_cast<char*>(&score), sizeof(score));
        std::cout << playerName << ": " << score << std::endl;
    }

    inFile.close();
}


 






