#include "Ball.h"

void Ball::Update(std::vector<Wall> walls, std::vector<Brick>& bricks, Pad* pad) {
    Vector2 targetPos = position + direction;

    for (auto it = walls.begin(); it != walls.end(); it++) {
        if (it->GetPosition() == targetPos) {
            // colisión con pared
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
            // colisión con ladrillo
            it->TakeDamage(GetDamage());
            direction.y *= -1;
        }
    }

    // verificar colisión con la paleta
    Vector2 padPos = pad->GetPosition();
    int padWidth = pad->GetWidth();
    if (targetPos.y == padPos.y - 1 && targetPos.x >= padPos.x && targetPos.x <= padPos.x + padWidth - 1) {
        // calcular la sección en la que colisionó la pelota
        float sectionWidth = (float)padWidth / 3.0f;
        float ballX = targetPos.x - padPos.x;
        float section = std::floor(ballX / sectionWidth);

        // establecer la nueva dirección basada en la sección de colisión
        switch ((int)section) {
        case 0:
            direction.x = -1;
            direction.y = -1;
            break; // sección izquierda
        case 1:
            direction.x = 0;
            direction.y = -1;
            break; // sección media
        case 2:
            direction.x = 1;
            direction.y = -1;
            break; // sección derecha
        default:
            direction.x = 0;
            direction.y = -1;
            break; // sección por defecto (en caso de error)
        }
    }

    // verificar si la pelota ha llegado a la pared de abajo
    if (targetPos.y >= walls.back().GetPosition().y) {
        // destruir la pelota
        delete this;

    }
    else {
        position = position + direction;
    }
}


