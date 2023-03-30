#include "GameManager.h"

int main() {
	GameManager game;

	while (game.isPlaying)
	{
		game.Update();
	}
}