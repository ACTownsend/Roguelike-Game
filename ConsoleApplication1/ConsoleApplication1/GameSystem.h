#pragma once
#include "Player.h"
#include "Level.h"
#include <string>


using namespace std;

class GameSystem	//adam
{
public:
	GameSystem(string levelFileName, int level, int health, int maxHealth, int attack, int defense, int experience);
	

	void playGame();
	void playerMove();
	int Menu();


private:
	Level _level;
	Player _player;
};

