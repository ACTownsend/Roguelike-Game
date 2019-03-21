#pragma once
#include <string>
using namespace std;
class Player	//shazzy
{
public:
	Player();
	void init(int level, int health, int maxHealth, int attack, int defense, int experience, int score);

	void setPosition(int x, int y);

	void getPosition(int &x, int &y);
	int attack();
	void heal();
	void addEXP(int experience);
	void updatescore();
	void addScore();
	void assignName(string player_name);



	int getHealth()//adam2
	{
		return _health;
	}
	int getAttack()//adam2
	{
		return _attack;
	}
	int getLevel()//adam2
	{
		return _level;
	}
	int getMaxHealth()//adam2
	{
		return _maxHealth;
	}
	int getDefense()//adam
	{
		return _defense;
	}
	int getEXP()//adam2
	{
		return _experience;
	}
	int getScore()//adam2
	{
		return _experience;
	}
	string getName()//adam2
	{
		return _name;
	}

	string getStat() //dragos2
	{
		string lvl = to_string(_level);
		string hp = to_string(_health);
		string dmg = to_string(_attack);
		string def = to_string(_defense);
		string xp = to_string(_experience);
		string score = to_string(_score);


		string stats = "Name: ";
		stats.append(_name);

		stats.append(" Level: ");
		stats.append(lvl);

		stats.append(" Health: ");
		stats.append(hp);

		stats.append(" Attack: ");
		stats.append(dmg);

		stats.append(" Defense: ");
		stats.append(def);

		stats.append(" EXP: ");
		stats.append(xp);

		stats.append(" Score: ");
		stats.append(score);
		return stats;
	}


	int takeDamage(int attack);

private:
	int _level;
	int _health;
	int _maxHealth;
	int _attack;
	int _defense;
	int _experience;
	int _score;
	string _name;


	int _x;
	int _y;


};

