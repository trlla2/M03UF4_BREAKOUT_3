#include "Pad.h"


void Pad::Render() {
    // Mueve el cursor a la posición de la pala
    ConsoleXY(position.x, position.y);

    // Cambia el color
    ConsoleSetColor(ConsoleColor::DARKMAGENTA, ConsoleColor::BLACK);

    // Dibuja la pala
    for (int i = 0; i < width; i++) {
        std::cout << "-";
    }
}

Vector2 Pad::GetPosition() {
    return position;
}

void Pad::SetPosition(Vector2 newPos) {
    position = newPos;
}

int Pad::GetWidth() {
    return width;
}
