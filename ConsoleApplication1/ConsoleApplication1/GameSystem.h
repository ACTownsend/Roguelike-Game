#pragma once
#include "Player.h"
#include "Level.h"
#include <string>


using namespace std;

class GameSystem	//adam
{
public:
	GameSystem(string levelFileName, int level, int health, int maxHealth, int attack, int defense,int experience, int score);
	

	void playGame(string player_name);
	void playerMove();
	int Menu();
	string getName(string name);


private:
	Level _level;
	Player _player;
};

