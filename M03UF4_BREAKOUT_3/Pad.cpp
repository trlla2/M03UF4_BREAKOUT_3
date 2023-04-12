#include "Pad.h"


void Pad::Render() {
    
    ConsoleXY(position.x, position.y);

   
    ConsoleSetColor(ConsoleColor::DARKMAGENTA, ConsoleColor::BLACK);

    
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
