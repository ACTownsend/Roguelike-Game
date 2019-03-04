#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Shop.h"
#include "monster.h"
#include <random>
#include <ctime>


using namespace std;


class Level	//adam
{
public:
	Level();

	void load(string fileName, Player &player, Shop &shop);
	void print();

	void movePlayer(char input, Player &player);
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

	void updateMonsters(Player &player);

	void restartGame();



private:
	vector <string> _levelData;
	void processPlayerMove(Player &player, int targetx, int targety);
	void processMonsterMove(Player &player, int monsterIndex, int targetx, int targety);
	void battleMonster(Player &player, int targetx, int targety);
	void enterShop(Shop &shop, Player &player, int targetx, int targety);
	vector <monster> _monsters;
	vector <Shop> _shop;

	
};

