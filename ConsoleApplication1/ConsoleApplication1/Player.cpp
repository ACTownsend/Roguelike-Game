#include "pch.h"
#include "Player.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Player::Player()	//shazzy
{
	_x = 0;
	_y = 0;
}


void Player::init(int level, int health, int attack, int defense, int experience)	//shazzy
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}


void Player::setPosition(int x, int y)	//shazzy
{
	_x = x;
	_y = y;
}

void Player::getPosition(int &x, int &y)	//shazzy
{
	x = _x;
	y = _y;
}

void Player::addEXP(int experience)	//lewis
{
	_experience = experience + experience;
	while (_experience > 50)
	{
		cout << "You Levelled Up!\n" << endl;
		_experience = _experience - _experience;
		_attack = _attack + 10;
		_level = _level++;
		_health = _health + 3;
		_defense = _defense + 5;
		system("PAUSE");
	}
}

int Player::attack()	//dragos
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> attackRoll(0, _attack);
	return attackRoll(randomEngine);
}

int Player::takeDamage(int attack) //lewis
{
	attack -= _defense;
	if (attack > 0)
	{
		_health = _health - attack;
		if (_health <= 0)
		{
			return 1;
		}
	}

	return 0;
}

