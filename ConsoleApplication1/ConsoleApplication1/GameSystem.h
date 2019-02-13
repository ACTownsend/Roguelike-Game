#pragma once
#include "Player.h"
#include <string>
#include "Level.h"

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFileName);

	void playGame();
	void playerMove();
	void restartGame();
	int Menu();


private:
	Level _level;
	Player _player;
};

