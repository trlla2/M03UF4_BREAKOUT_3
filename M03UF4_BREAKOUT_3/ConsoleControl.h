#pragma once
#include <conio.h>
#include <windows.h>
#include <iostream>
enum ConsoleColor { 
	BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKYELLOW, LIGHTGREY,
	DARKGREY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor);
void ConsoleXY(short int x, short int y);
