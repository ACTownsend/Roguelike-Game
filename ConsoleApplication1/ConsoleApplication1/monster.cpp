#include "pch.h"
#include "monster.h"
#include <random>
#include <ctime>


monster::monster(string name, char tile, int level, int attack, int defense, int health, int XP)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_XPValue = XP;

}

void monster::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void monster::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int monster::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> attackRoll(0, _attack);
	return attackRoll(randomEngine);
}

int monster::takeDamage(int attack)
{
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

char monster::getMove(int playerX, int playerY)
{
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
		if (absDX > absDY)	//move X axis
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
		else  //move Y axis
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