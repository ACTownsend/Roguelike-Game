#include "pch.h"
#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include "GameSystem.h"

Level::Level()
{
	print();
}


void Level::load(string fileName, Player &player)
{	//loads level
	ifstream file;

	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line))
	{
		_levelData.push_back(line);
	}

	file.close();

	//process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j= 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];


			switch (tile)
			{
				case '@':
					player.setPosition(j, i);
					break;

			}
		}
	}
}

void Level::print()
{

	//cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}


void Level::movePlayer(char input, Player &player)
{

	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);
	char moveTile;


	switch (input)
	{
	case 'w':
	case 'W':
		moveTile = getTile(playerX, playerY - 1);
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 'a':
	case 'A':
		moveTile = getTile(playerX - 1, playerY);
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 's':
	case 'S':
		moveTile = getTile(playerX, playerY + 1);
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'd':
	case 'D':
		moveTile = getTile(playerX + 1, playerY);
		processPlayerMove(player, playerX + 1, playerY);
		break;
	case 27:
		restartGame();
		

	default:
		cout << "Invalid Input" << endl;
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetx, int targety)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetx, targety);
	switch (moveTile)
	{
	case'#':
		cout << "you ran into a wall" << endl;
		system("PAUSE");
		break;
	case'.':
		player.setPosition(targetx, targety);
		setTile(playerX, playerY, '.');
		setTile(targetx, targety, '@');
	}
}
void Level::restartGame()
{

	GameSystem gameSystem("level1.txt");
	gameSystem.Menu();

	gameSystem.playGame();
}