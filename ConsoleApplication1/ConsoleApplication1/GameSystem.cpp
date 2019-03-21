#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

GameSystem::GameSystem(string levelFileName, int level, int health, int maxHealth, int attack, int defense, int experience, int score)	//adam2
{
	_player.init(level, health, maxHealth, attack, defense, experience, score);
	
	_level.load(levelFileName, _player);
	_level.print();


}



void GameSystem::playGame(string player_name)	//adam
{
	bool isDone = false;
	_player.assignName(player_name);

	while (isDone != true)
	{
		system("cls");
		_level.print();
		playerMove();
		_level.updateMonsters(_player);
		_player.updatescore();
	}	
}


void GameSystem::playerMove()	//shazzy
{


	char input;

	cout << "Enter a move command (w/a/s/d):\n ";
	cout << _player.getStat() << endl;
	input = _getch();

	_level.movePlayer(input, _player);

}









