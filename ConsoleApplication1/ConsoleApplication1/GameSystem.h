#pragma once
#include "Player.h"
#include "Level.h"
#include <string>


using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFileName);

	void playGame();
	void playerMove();
	int Menu();


private:
	Level _level;
	Player _player;
};

