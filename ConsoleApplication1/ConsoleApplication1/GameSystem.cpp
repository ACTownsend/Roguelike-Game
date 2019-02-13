#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <conio.h>

using namespace std;

GameSystem::GameSystem(string levelFileName)
{
	_player.init(1, 100, 10, 10, 0);
	
	_level.load(levelFileName, _player);
	_level.print();


}

void GameSystem::playGame()
{
	bool isDone = false;

	while (isDone != true)
	{
		system("cls");
		_level.print();
		playerMove();
	}	
}


void GameSystem::playerMove()
{


	char input;

	cout << "Enter a move command (w/a/s/d): ";
	input = _getch();

	_level.movePlayer(input, _player);

}





