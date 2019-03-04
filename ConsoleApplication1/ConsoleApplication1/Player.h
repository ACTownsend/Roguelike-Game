#pragma once
#include <string>
using namespace std;
class Player	//shazzy
{
public:
	Player();
	void init(int level, int health, int maxHealth, int attack, int defense, int experience);

	void setPosition(int x, int y);

	void getPosition(int &x, int &y);
	int attack();
	void heal();
	void addEXP(int experience);

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

	string getStat() //dragos2
	{
		string lvl = to_string(_level);
		string hp = to_string(_health);
		string dmg = to_string(_attack);
		string def = to_string(_defense);
		string xp = to_string(_experience);


		string stats = "Level: ";
		stats.append(lvl);

		stats.append(" Health: ");
		stats.append(hp);

		stats.append(" Attack: ");
		stats.append(dmg);

		stats.append(" Defense: ");
		stats.append(def);

		stats.append(" EXP: ");
		stats.append(xp);
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


	int _x;
	int _y;


};

