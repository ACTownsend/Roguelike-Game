#include "pch.h"
#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include "GameSystem.h"
#include "conio.h"
#include "libsqlite.hpp"

Level::Level() //adam
{
	print();
}


void Level::load(string fileName, Player &player)	//adam
{	//takes an input of the filename and the player class and initiates the player and the monsters positions on the level
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
		_levelData.push_back(line);		//loads the level
	}
	loadEnemy("bossdesign.txt");
	loadPlayer("playerdesign.txt");
	int playerDef = player.getDefense();
	int playerAtk = player.getAttack();


	file.close();

	
	char tile;
	for (int i = 0; i < _levelData.size(); i++)		//processes the level
	{
		for (int j= 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];


			switch (tile)
			{
				case '@':
					player.setPosition(j, i);		//finds the @ symbol and sets it to the players position
					break;
				case 'M':
					_monsters.push_back(monster("Monster", tile, 2,playerDef+5,10,playerAtk+5,30, playerDef + 5));	//initiates the monsters
					_monsters.back().setPosition(j, i);		//sets monsters positions to the M symbols on the level
					break;


			}
		}
	}
}

void Level::print()	//adam
{
	//prints the level

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());		
	}
	printf("\n");
}


void Level::movePlayer(char input, Player &player)		//lewis
{
	//takes an input of a button press and the player class and moves the player accordingly
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
	case 27:		//escape to quit the game
		updateDatabase(player);
		restartGame();
		

	default:
		cout << "Invalid Input" << endl;
		system("PAUSE");
		break;
	}
}

void Level::updateMonsters(Player &player)	//costa
{
	//Takes an input of the player class and processes the movement of the monsters based on the move function in the monster class
	char aiMove;
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	int monsterX;
	int monsterY;
	

	for (int i = 0; i < _monsters.size(); i++)
	{
		aiMove = _monsters[i].getMove(playerX, playerY);	//gets the movement key for each of the monsters
		_monsters[i].getPosition(monsterX, monsterY);		//gets the position of each of the monsters

		switch (aiMove)	//processes the movement for each of the monsters depending on the result of the getMove function
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


char Level::getTile(int x, int y)	//costa
{
	//Gets the current tile position
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) //costa
{
	//sets the current tile
	_levelData[y][x] = tile;
}

void Level::processPlayerMove(Player &player, int targetx, int targety)	//shazzy
{
	//takes an input of the player class, the target x position and the target y position and processes the player movement. Initiates a battle with a monster if the user walks into a monster
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetx, targety);
	switch (moveTile)
	{
	case'.':		//swaps the target tile with the current tile (actually moves the player)
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

void Level::processMonsterMove(Player &player, int monsterIndex, int targetx, int targety)	//costa
{
	//takes an input of the player, the current monster and the target x,y position and processes the monster movement
	int playerX;
	int playerY;
	int monsterX;
	int monsterY;
	_monsters[monsterIndex].getPosition(monsterX, monsterY);
	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetx, targety);
	switch (moveTile)
	{
	case'.':		//swaps the target tile with the current tile (actually moves the monsters)
		_monsters[monsterIndex].setPosition(targetx, targety);
		setTile(monsterX, monsterY, '.');
		setTile(targetx, targety, _monsters[monsterIndex].getTile());
	case'#':
		break;
	case'@':
		battleMonster(player, monsterX, monsterY);	//initiates a fight with the player if the monster walks into the player
		break;
	default:
		break;
	}


}

void Level::battleMonster(Player &player, int targetx, int targety)	//adam
{
	//takes an input of the player and the target x,y positions and enters a battle scene for fighting the monster
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackRoll;
	int attackResult;
	int defense;
	int actualDamage;

	
	player.getPosition(playerX, playerY);

	for (int i = 0; i < _monsters.size(); i++)
	{
		_monsters[i].getPosition(enemyX, enemyY);
		
		if (targetx == enemyX && targety == enemyY)		//simon
		{
			system("cls");
			int playerstart = player.getMaxHealth();
			int start = _monsters[i].getMaxHealth();
			int stars = _monsters[i].getHealth();
			int stars2 = player.getHealth();

			printEnemy();
			EnemyHealth(start, stars);				//prints the enemy sprite and the player sprite, as well as their respective health bars
			printPlayer();
			playerHealth(playerstart, stars2);
		begin:
			while (start>0)		//adam
			{
				cout << "1.Basic Attack\n2.Restore Health\n";	
				char input = _getch();
				switch (input)
				{
				case '1':		//does a random amount of damage to the enemy and updates the health bar of the enemy
					defense = _monsters[i].getDefense();
					attackRoll = player.attack();
					actualDamage = attackRoll - defense;
					system("cls");
					printEnemy();
					
					if (actualDamage < 0)
					{
						actualDamage = 1;
					}
					
					cout << "\nPlayer attacked monster with a roll of " << actualDamage << endl;
					attackResult = _monsters[i].takeDamage(attackRoll);
					stars = _monsters[i].getHealth();
					playerDamage(actualDamage, playerstart, stars);
					break;
				case '2':		//heals the player and updates the health bar
					system("cls");
					printEnemy();
					player.heal();
					cout << "You healed 5 health" << endl;
					attackResult = 0;
					playerDamage(0, playerstart, stars);
					break;
				default:
					system("cls");
					printEnemy();
					cout << "\nINVALID INPUT" << endl;
					system("PAUSE");
					playerDamage(0, playerstart, stars);
					return;
				}




				if (attackResult != 0)		//checks to see if the monster has 0 life left
				{
					setTile(targetx, targety, '.');
					system("cls");
					print();
					cout << "\nYou killed the monster!" << endl;

					_monsters[i] = _monsters.back();		//remove monster from the vector (killing it)
					_monsters.pop_back();
					i--;

					system("PAUSE");
					player.addEXP(attackResult);
					player.addScore();
					if (_monsters.empty())		//checks to see if any monsters are alive, if not moves on to the next level
					{
						int tempLvl = player.getLevel();
						int tempHealth = player.getHealth();
						int tempMax = player.getMaxHealth();
						int tempAtk = player.getAttack();
						int tempDef = player.getDefense();
						int tempXP = player.getEXP();
						int tempScr = player.getScore();
						string tempName = player.getName();
						cout << "\nLevel complete!" << endl;
						system("PAUSE");

						static default_random_engine randomEngine(time(NULL));
						uniform_int_distribution <int> levelGen(1, 5);
						char ranlevel = levelGen(randomEngine);

						string levelNo = to_string(ranlevel);
						string level = "level";
						level.append(levelNo);
						level.append(".txt");

						GameSystem gameSystem(level, tempLvl, tempHealth, tempMax, tempAtk, tempDef, tempXP, tempScr);	//moves onto a different level


						gameSystem.playGame(tempName);
						break;

					}

					return;
				}
				defense = player.getDefense();

				//monster turn to attack the player with a random amount of damage, updating the player health bar
				attackRoll = _monsters[i].attack();
				actualDamage = attackRoll - defense;


				if (actualDamage < 0)
				{
					actualDamage = 1;
				}
				cout << "\nMonster attacked player with a roll of " << actualDamage << endl;
				attackResult = player.takeDamage(attackRoll);
				printPlayer();
				stars2 = player.getHealth();
				enemyDamage(actualDamage, start, stars2);		//updates the healthbar
				if (attackResult != 0)		//checks to see if the player has died
				{
					setTile(playerX, playerY, 'X');
					system("cls");
					print();
					cout << "\nYOU DIED" << endl;
					updateDatabase(player);	//adds the player name and the score to the database
					system("PAUSE");
					system("cls");
					printLeaderboard();		//prints the top 10 players and their scores
					restartGame();		//restarts the game
					return;
				}
				goto begin;
			}
			
			return;
		}
			
		
	}
}

void Level::restartGame()	//adam
{
	//restarts the game by picking another random level and going back to the main menu
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> levelGen(1, 5);		//picks a random level between 1 and 5
	char ranlevel = levelGen(randomEngine);

	string levelNo = to_string(ranlevel);
	string level = "level";
	level.append(levelNo);		//transforms the random number into a name of one of the text files
	level.append(".txt");

	GameSystem gameSystem(level, 1, 20, 20, 20, 5, 0, 100);
	gameSystem.Menu();
	string name = gameSystem.getName("hi");		//fetches the user inputted name
	gameSystem.playGame(name);
}

int Level::printLeaderboard()		//lewis
{
	//queries the database for the top 10 results
	try
	{
		sqlite::sqlite db("RogueGame.db");	//connects to the database

		cout << "NAME	" << "SCORE" << endl;
		auto s = db.get_statement();
		s->set_sql("SELECT    * "
			"FROM Leaderboard ORDER BY Score DESC LIMIT 10;");	//queries the database

		s->prepare();

		while (s->step())
		{
			cout << s->get_text(0) << "			" << s->get_text(1) << "\n";		//outputs the data from the first and second columns in the database

		}
		cout << endl;
	}
	catch (sqlite::exception e)
	{
		cerr << e.what() << endl;
	}
	system("PAUSE");
	restartGame();
	return 0;
}





void Level::loadEnemy(string fileName) {		//simon
	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;
	while (getline(file, line)) {
		_bossData.push_back(line);
	}
	file.close();


}
void Level::printEnemy() {		//simon
	for (int i = 0; i < _bossData.size(); i++) {
		printf("%s\n", _bossData[i].c_str());
	}
}

void Level::EnemyHealth(int start, int stars) {		//simon
	cout << "						";
	for (int i = 0; i <= start; i++)
		cout << "_";
	cout << "" << endl;
	cout << "						";
	for (int b = 0; b < start; b++) {
		cout << "*";
	}
	cout << "/" << endl;

}

void Level::loadPlayer(string fileName) {		//simon
	ifstream file;

	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;
	while (getline(file, line)) {
		_playerData.push_back(line);
	}
	file.close();


}
void Level::printPlayer() {			//simon
	for (int i = 0; i < _playerData.size(); i++) {
		printf("%s\n", _playerData[i].c_str());
	}
}

void Level::playerDamage(int dmg, int start, int stars)	//simon
{
	 
	int h = start - dmg;
	if (h > 0 && start > dmg) {
		cout << "						";
		for (int c = 0; c <= start; c++)
			cout << "_";
		cout << "" << endl;
		cout << "						";
		for (int d = 0; d < stars; d++)
			cout << "*";

		for (int z = 0; z < (start - stars); z++)
			cout << " ";
		cout << "/" << endl;
	}

	else
	{
		cout << "" << endl;
		cout << "## DEAD ##" << endl;
	}


}
void Level::enemyDamage(int dmg1, int start, int stars2) {		//simon
	int h1 = start - dmg1;
	if (h1 > 0 && start > dmg1) {

		for (int c1 = 0; c1 <= start; c1++)
			cout << "_";
		cout << "" << endl;
		for (int d1 = 0; d1 < stars2; d1++)
			cout << "*";

		for (int z1 = 0; z1 < (start - stars2); z1++)
			cout << " ";
		cout << "/" << endl;
	}

	else
	{
		cout << "" << endl;
		cout << "## DEAD ##" << endl;
	}



}

void Level::playerHealth(int start, int stars2) {		//simon
	for (int i = 0; i <= start; i++)
		cout << "_";
	cout << "" << endl;
	for (int b = 0; b < stars2; b++) {
		cout << "*";
	}

	cout << "/" << endl;
}

void Level::updateDatabase(Player &player) //lewis
{
	//updates the database by inserting the player name and score
	try    //lewis
	{
		sqlite::sqlite db("RogueGame.db");		//connects to the database

		auto cur = db.get_statement();

		string name = player.getName();	
		int score = player.getScore();


		cur->set_sql("INSERT INTO leaderboard (Name, Score) "		//inserts the data
			"VALUES (?, ?);");
		cur->prepare();

		cur->bind(1, name);		//uses the user name and score to insert
		cur->bind(2, score);


		cur->step();
	}
	catch (sqlite::exception e)
	{
		cerr << e.what() << endl;
	}
}

