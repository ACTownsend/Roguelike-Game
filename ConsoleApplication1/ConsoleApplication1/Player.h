#pragma once
#include <string>
#include <stdio.h>
class Player	//shazzy
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	void setPosition(int x, int y);

	void getPosition(int &x, int &y);
	int attack();

	void addEXP(int experience);

	int getHealth()//adam
	{
		return _health;
	}
	int getAttack()//dragos
	{
		return _attack;
	}
	int getLevel()//dragos
	{
		return _level;
	}
	int getDefense()//dragos
	{
		return _defense;
	}
	int getExperience()//dragos
	{
		return _experience;
	}

	int getStats()
	{
		char buffer [50];
		int n;
		n = sprintf(buffer, "Level: %d  Health: %d", _level, _health);
		return n;
	}
	int takeDamage(int attack);

private:
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;


	int _x;
	int _y;


};

