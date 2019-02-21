#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>

using namespace std;

GameSystem::GameSystem(string levelFileName)	//adam
{
	_player.init(1, 20, 20, 5, 0);
	
	_level.load(levelFileName, _player);
	_level.print();


}

void GameSystem::playGame()	//adam
{
	bool isDone = false;

	while (isDone != true)
	{
		system("cls");
		_level.print();
		playerMove();
		_level.updateMonsters(_player);
	}	
}


void GameSystem::playerMove()	//shazzy
{


	char input;

	cout << "Enter a move command (w/a/s/d):\n ";
	//cout <<"Health:"<< _player.getHealth() << " Attack:" << _player.getAttack() << " Level:" << _player.getLevel() << " Experience:" << _player.getExperience() << " Defense:" << _player.getDefense() << endl;
	cout << _player.getStats() << endl;
	input = _getch();

	_level.movePlayer(input, _player);

}







