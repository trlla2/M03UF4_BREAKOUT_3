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
	case GameManager::CREDITS:
		Credits();

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
	bool press3;
	bool press0;
	while (!keyPressed) {
		std::cout << ",-,---.             .           .  \n";
		std::cout << " '|___/ ,-. ,-. ,-. | , ,-. . . |- \n";
		std::cout << " ,|   \ |   |-' ,-| |<  | | | | |  \n";
		std::cout << "`-^---' '   `-' `-^ ' ` `-' `-^ `' \n";
		std::cout << "\n\n";
		std::cout << "Main Menu \n\n";
		std::cout << "Press 1 to play" << std::endl;
		std::cout << "Press 2 to Ranking" << std::endl;
		std::cout << "Press 3 to Credits" << std::endl;
		std::cout << "Press 0 to exit" << std::endl;
		
		 press1 = GetAsyncKeyState('1') != 0;
		 press2 = GetAsyncKeyState('2') != 0;
		 press3 = GetAsyncKeyState('3') != 0;
		 press0 = GetAsyncKeyState('0') != 0;
		
		 keyPressed = press1 || press2 || press3 || press0;

		Sleep(sleepTime);
		system("cls");

	}

	if (press1)
		currentScene = Scene::GAMEPLAY;
	else if (press2)
		currentScene = Scene::HIGHSCORE;
	else if (press3)
		currentScene = Scene::CREDITS;
	else 
		isPlaying = false;
}

void GameManager::GamePlay() {
	int sleepTime = 100;
	bool gameplay = true;
	int score = 0;
	int brokenBlocks = 0;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	InitGameplay(25, 20, &playerPad, &ball, walls, bricks);

	while (gameplay) {

		if (ball->GetLives() == 0) {
			system("cls");
			currentScene = Scene::MENU;
			saveScore(score);
			gameplay = false;

		}
		else
		{ 
			bool leftPressed = GetAsyncKeyState(VK_LEFT) != 0;
			bool rightPressed = GetAsyncKeyState(VK_RIGHT) != 0;

			if (leftPressed && playerPad->GetPosition().x > 0) {
				playerPad->SetPosition(Vector2(playerPad->GetPosition().x - 1, playerPad->GetPosition().y));
			}

			if (rightPressed && playerPad->GetPosition().x + playerPad->GetWidth() < 25) {
				playerPad->SetPosition(Vector2(playerPad->GetPosition().x + 1, playerPad->GetPosition().y));
			}

			ball->Update(walls, bricks, playerPad, brokenBlocks);



			playerPad->Render();

			for (std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++) {
				it->Render();
			}

			for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++) {
				it->Render();
			}

			ball->Render();


			Sleep(sleepTime);
			system("cls");
		}
	}
}


void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& brick) {
	//PAD
	



	*p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);

	//WALLS
	//first corner(top left)
	w.push_back(Wall(WallType::CORNER, Vector2(0, 0)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, 0)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, 0)));

	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < 2; j++) {
			w.push_back(Wall(WallType::VERTICAL, Vector2(j * (width - 1), i + 1)));
		}
	}

	w.push_back(Wall(WallType::CORNER, Vector2(0, height - 1)));
	for (int i = 1; i < width - 1; i++)
		w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, height - 1)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, height - 1)));

	//BRICKS
	for (int i = 1; i <= 3; i++) { //FILES
		for (int j = 1; j < width - 1; j++) {
			brick.push_back(Brick(Vector2(j, i), 1));
		}

		//BALL
		*b = new Ball(Vector2(width / 2, height / 2), Vector2(0, 1), 1);

	}
	
}

void GameManager::Highscore() {
	bool press1;
	bool keyPressed = false;
	int score;

	std::cout << ",-_/,.       .                       \n";
	std::cout << "' |_|/ . ,-. |-. ,-. ,-. ,-. ,-. ,-. \n";
	std::cout << " /| |  | | | | | `-. |   | | |   |-' \n";
	std::cout << " `' `' ' `-| ' ' `-' `-' `-' '   `-' \n";
	std::cout << "          ,|                         \n";
	std::cout << "          `'                         \n\n";
	loadScore();
	std::cout << "\n\n";
	//Highscore stuff
	std::cout << "Pres 1 to go to menu...";
	
	while (!keyPressed) {
		press1 = GetAsyncKeyState('1') != 0;

		keyPressed = press1;

		Sleep(100);
		system("cls");

		currentScene = Scene::MENU;
	}

}


void GameManager::Credits() {
	bool press1;
	bool keyPressed = false;

	std::cout << " ,--.           .   .      \n";
	std::cout << "| `-' ,-. ,-. ,-| . |- ,-. \n";
	std::cout << "|   . |   |-' | | | |  `-. \n";
	std::cout << "`--'  '   `-' `-^ ' `' `-' \n\n";
	std::cout << "Made by: \n";
	std::cout << "Roc Allue \n";
	std::cout << "Aleix Ramirez \n";
	std::cout << "Pres 1 to go to menu...";

	while (!keyPressed) {
		press1 = GetAsyncKeyState('1') != 0;

		keyPressed = press1;
	}
	Sleep(100);
	system("cls");

	currentScene = Scene::MENU;
}

void GameManager::saveScore( int score) {
	std::string (namePlayer);
	std::cout << "Qual es tu nombre?\n";
	std::cin >> namePlayer;

	std::ofstream outfile;
	outfile.open("scores.bin", std::ios::binary | std::ios::app);
	size_t size = namePlayer.size();
	outfile.write(reinterpret_cast<char*> (&namePlayer), sizeof(size_t));
	outfile.write(namePlayer.c_str(), sizeof(char) * size);
	outfile.write(reinterpret_cast<char*>(&score), sizeof(int));


	outfile.close();
}

void GameManager::loadScore() {
	std::ifstream in("scores.bin", std::ios::in | std::ios::binary);

	if (!in) {
		std::cout << "No se puede abrir el archivo" << std::endl;
		return;
	}

	while (in) {
		std::string a;
		int points;
		size_t readSize;
		size_t size = a.size();

		in.read(reinterpret_cast<char*>(&readSize), sizeof(size_t));
		char* temp = new char[readSize + 1];
		in.read(temp, readSize);
		temp[size] = '\0';
		std::string name = temp;
		delete[] temp;


		in.read(reinterpret_cast<char*>(&points), sizeof(int));

		if (in) {
			std::cout << "Jugador: " << name << ", Puntuación: " << points << std::endl;
		}
	}

	in.close();

}


