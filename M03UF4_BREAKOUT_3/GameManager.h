#pragma once
#include <iostream>
#include <Windows.h>

class GameManager {
public:
	enum Scene{MENU, GAMEPLAY, HIGHSCORE};
	Scene currentScene;
	bool isPlaying;


	GameManager()
		: currentScene(MENU), isPlaying(true) {}
	void Update();

private:
	void Menu();
	void GamePlay();
	void Highscore();
};	