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
	int sleepTime = 16;
	std::cout << "Menu" << std::endl;
	Sleep(sleepTime);
}

void GameManager::GamePlay() {
	int sleepTime = 16;
	std::cout << "GP" << std::endl;
	Sleep(sleepTime);
}
void GameManager::Highscore() {
	std::cout << ">Highscore" << std::endl;
}