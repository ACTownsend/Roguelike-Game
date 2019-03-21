#pragma once
#include <string>
using namespace std;
class monster	
{
public:
	monster(string name, char tile, int level, int attack, int defense, int health, int XP);

	void setPosition(int x, int y);
										//simon
	void getPosition(int &x, int &y);

	char getTile()
	{
		return _tile;		//dragos
	}

	int getDefense()
	{
		return _defense;
	}

	int attack();	//dragos

	int takeDamage(int attack);	//lewis

	
	char getMove(int playerX, int playerY);	//costa

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

