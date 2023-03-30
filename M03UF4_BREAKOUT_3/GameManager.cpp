#include "GameManager.h"

void GameManager::Update() {
	switch (currentScene)
	{
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		GamePlay();
		break;
	case GameManager::HIGHSCORE:
		Highscore();
		break;
	default:
		break;
	}
}

void GameManager::Menu() {
	int sleepTime = 500;
	bool keyPressed = false;
	bool press1;
	bool press2;
	while (!keyPressed) {
		std::cout << "Main Menu \n\n";
		std::cout << "Press 1 to play" << std::endl;
		std::cout << "Press 2 to exit" << std::endl;
		
		 press1 = GetAsyncKeyState('1') != 0;
		 press2 = GetAsyncKeyState('2') != 0;
		
		 keyPressed = press1 || press2;

		Sleep(sleepTime);
		system("cls");

	}

	if (press1)
		currentScene = Scene::GAMEPLAY;
	else 
		isPlaying = false;
}

void GameManager::GamePlay() {
	int sleepTime = 16;
	std::cout << "GP" << std::endl;
	Sleep(sleepTime);
}
void GameManager::Highscore() {
	std::cout << ">Highscore" << std::endl;
}