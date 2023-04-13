#pragma once
#include <fstream>
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
    int score; 
    int lives = 3;
    void RenderScore() {
        ConsoleXY(50, 0);
        std::cout << "Score: " << score;
    }
    void RenderLives() {
        ConsoleXY(40, 0);
        std::cout << "Lives: " << lives;
    }

public:
    Ball(Vector2 p, Vector2 dir, int dmg)
        :position(p), direction(dir), damage(dmg), score(0), lives(3) {}

    void SetDirection(Vector2 dir) {
        direction = dir;
    }

    void Bounce(Pad* pad);
    void Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad, int brokenBlocks);
    int GetDamage() { return damage; }
    Vector2 GetDirection();
    Vector2 GetPosition();
    void Render() {
        ConsoleXY(position.x, position.y);
        std::cout << "@";
        RenderScore();
        RenderLives();
    }
    int GetScore() const {
        return score;
    }
    int GetLives() const {
        return lives;
    }

};




