#pragma once
#include <string>
using namespace std;
class monster
{
public:
	monster(string name, char tile, int level, int attack, int defense, int health, int XP);

	void setPosition(int x, int y);

	void getPosition(int &x, int &y);

	char getTile()
	{
		return _tile;
	}

	int attack();

	int takeDamage(int attack);

	//move monsters
	char getMove(int playerX, int playerY);
private:
	string _name;
	char _tile;

	int _level;
	int _attack;
	int _defense;
	int _health;
	int _XPValue;

	int _x;
	int _y;
};

