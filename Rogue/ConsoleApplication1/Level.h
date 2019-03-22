#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "monster.h"
#include <random>
#include <ctime>



using namespace std;


class Level	//adam
{
public:
	Level();

	void load(string fileName, Player &player);
	void print();

	void movePlayer(char input, Player &player);
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

	void updateMonsters(Player &player);
	

	void restartGame();
	int printLeaderboard();


	void EnemyHealth(int start, int stars);
	void loadEnemy(string bossFileName);


	void printEnemy();
	void loadPlayer(string playerFileName);
	void printPlayer();
	void playerDamage(int dmg, int start, int stars);
	void enemyDamage(int dmg1, int start, int stars2);
	void playerHealth(int playerstart, int stars2);
	void updateDatabase(Player &player);

private:
	vector <string> _levelData;
	void processPlayerMove(Player &player, int targetx, int targety);
	void processMonsterMove(Player &player, int monsterIndex, int targetx, int targety);
	void battleMonster(Player &player, int targetx, int targety);
	vector <monster> _monsters;


	//simon
	vector < string > _bossData;
	vector <string> _playerData;
	
};

