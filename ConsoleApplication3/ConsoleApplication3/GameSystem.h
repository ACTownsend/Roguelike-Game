#pragma once
#include <string>
#include "boss.h"
#include "player.h"
#include "startBarBoss.h"
using namespace std;
class GameSystem
{
public:
	GameSystem (string bossFile, string playerFile);
	
	void playGame();
private:
	boss _boss;
	player _player;
	int dmg=0;
	int e;
	int dmg1 = 0;
	int e1;
	int bossDmg = 8;
};

