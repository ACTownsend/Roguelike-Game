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
				case 'M':
					_monsters.push_back(monster("Monster", tile, 2,10,5,35,150));
					_monsters.back().setPosition(j, i);
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
		moveTile = getTile(playerX, playerY - 1);
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 'a':
		moveTile = getTile(playerX - 1, playerY);
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 's':
		moveTile = getTile(playerX, playerY + 1);
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'd':
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

void Level::updateMonsters(Player &player)
{
	char aiMove;
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	int monsterX;
	int monsterY;
	

	for (int i = 0; i < _monsters.size(); i++)
	{
		aiMove = _monsters[i].getMove(playerX, playerY);
		_monsters[i].getPosition(monsterX, monsterY);

		switch (aiMove)
		{
		case 'w':
			processMonsterMove(player,i, monsterX, monsterY - 1);
			break;
		case 'a':
			processMonsterMove(player,i, monsterX - 1, monsterY);
			break;
		case 's':
			processMonsterMove(player,i, monsterX, monsterY + 1);
			break;
		case 'd':
			processMonsterMove(player,i, monsterX + 1, monsterY);
			break;
		}
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
	case'.':
		player.setPosition(targetx, targety);
		setTile(playerX, playerY, '.');
		setTile(targetx, targety, '@');
	case'#':
		break;
	default:
		battleMonster(player, targetx, targety);
		break;
	}


}

void Level::processMonsterMove(Player &player, int monsterIndex, int targetx, int targety)
{
	int playerX;
	int playerY;
	int monsterX;
	int monsterY;
	_monsters[monsterIndex].getPosition(monsterX, monsterY);
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetx, targety);
	switch (moveTile)
	{
	case'.':
		_monsters[monsterIndex].setPosition(targetx, targety);
		setTile(monsterX, monsterY, '.');
		setTile(targetx, targety, _monsters[monsterIndex].getTile());
	case'#':
		break;
	case'@':
		battleMonster(player, monsterX, monsterY);
	default:
		break;
	}


}

void Level::battleMonster(Player &player, int targetx, int targety)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _monsters.size(); i++)
	{
		_monsters[i].getPosition(enemyX, enemyY);

		if (targetx == enemyX && targety == enemyY)
		{
			attackRoll = player.attack();
			cout << "\nPlayer attacked monster with a roll of "<< attackRoll << endl;
			system("PAUSE");
			attackResult = _monsters[i].takeDamage(attackRoll);
			if (attackResult != 0)
			{
				setTile(targetx, targety, '.');
				system("cls");
				print();
				cout << "\nYou killed the monster!" << endl;

				_monsters[i] = _monsters.back();		//remove monster from the vector
				_monsters.pop_back();
				i--;

				system("PAUSE");
				player.addEXP(attackResult);
				return;
			}

			//monster turn
			attackRoll = _monsters[i].attack();
			cout << "\nMonster attacked player with a roll of " << attackRoll << endl;
			system("PAUSE");
			attackResult = player.takeDamage(attackRoll);
			if (attackResult != 0)
			{
				setTile(playerX, playerY, 'X');
				system("cls");
				print();
				cout << "\nYOU DIED" << endl;
				system("PAUSE");

				restartGame();
				return;
			}
			return;
		}
	}
}


void Level::restartGame()
{

	GameSystem gameSystem("level1.txt");
	gameSystem.Menu();

	gameSystem.playGame();
}

