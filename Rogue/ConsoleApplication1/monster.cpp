#include "pch.h"
#include "monster.h"
#include <random>
#include <ctime>


monster::monster(string name, char tile, int level, int attack, int defense, int health, int XP, int maxHealth)	//costa
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_XPValue = XP;
	_maxHealth = maxHealth;

}

void monster::setPosition(int x, int y)	//simon
{
	_x = x;
	_y = y;
}

void monster::getPosition(int &x, int &y)	//simon
{
	x = _x;
	y = _y;
}

int monster::attack()	//dragos
{
	//returns a random number between 1 and the user's attack stat
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> attackRoll(1, _attack);
	return attackRoll(randomEngine);
}

int monster::takeDamage(int attack)	//lewis
{
	//take an input of the attack roll, updates the health of the enemy or gives the user experience if killed
	attack -= _defense;
	if (attack>0)
	{
		_health = _health - attack;
		if (_health<=0)
		{
			return _XPValue;
		}
	}

	return 0;
}

char monster::getMove(int playerX, int playerY)	//costa
{
	//takes an input of the players current X and Y position and returns a random movement key for the monster to move
	static default_random_engine randEngine(time(NULL));
	uniform_int_distribution <int> moveRoll(0, 8);
	int distance;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int absDX = abs(dx);
	int absDY = abs(dy);

	distance = absDX + absDY;

	if (distance <= 5)
	{
		if (absDX > absDY)	
		{
			if (dx > 0)
			{
				return 'a';
			}
			else
			{
				return 'd';
			}
		}
		else  
		{
			if (dy > 0)
			{
				return 'w';
			}
			else
			{
				return 's';
			}
		}
	}
	int randomMove = moveRoll(randEngine);

	switch (randomMove)
	{
	case 0:
		return 'w';
	case 1:
		return 'a';
	case 2:
		return 's';
	case 3:
		return 'd';

	default:
		return '.';
	}
}