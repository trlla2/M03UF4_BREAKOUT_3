#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Ball.h"
#include "Brick.h"
#include "Pad.h"
#include "Wall.h"

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
	void InitGameplay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& bricks);
	void Highscore();
};	