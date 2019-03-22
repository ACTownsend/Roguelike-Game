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


void Player::init(int level, int health, int maxHealth, int attack, int defense, int experience, int score)	//shazzy
{
	_level = level;
	_health = health;
	_maxHealth = maxHealth;
	_attack = attack;
	_defense = defense;
	_experience = experience;
	_score = score;
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
	//adds experience to the user and levells them up if they reach more than 50 experience
	_experience = _experience + experience;
	while (_experience >= 50)
	{
		cout << "You Levelled Up!\n" << endl;
		_experience = _experience - 50;
		_attack = _attack + 10;
		_level = _level++;
		_maxHealth = _maxHealth + 3;
		_defense = _defense + 5;
		system("PAUSE");
	}
}

int Player::attack()	//dragos
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> attackRoll(1, _attack);
	return attackRoll(randomEngine);
}

void Player::heal() //dragos
{
	_health = _health + 5;
	if (_health> _maxHealth)
	{
		_health = _maxHealth;
	}

	

}

int Player::takeDamage(int attack) //lewis
{
	//takes damage from the enemy and subtracts the players armour value from the damage
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

void Player::updatescore() //lewis
{
	//lowers the users score after every movement
	_score = _score - 1;
	if (_score <=0)
	{
		_score = 0;
	}
}

void Player::addScore() //lewis
{
	//adds to the user's score after they kill an enemy
	_score = _score + 150;
}

void Player::assignName(string player_name) //adam
{
	//sets the users name to whatever they input
	_name = player_name;
}


