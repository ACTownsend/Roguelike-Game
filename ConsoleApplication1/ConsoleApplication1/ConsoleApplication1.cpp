// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <random>
#include <ctime>




#include "GameSystem.h"

using namespace std;
string player_name;
int GameSystem::Menu()	//dragos
{
	char input;
	

wipe:
	system("cls");
	cout << R"(
				 _____  _____   _____    _____          __  __ ______ 
				|  __ \|  __ \ / ____|  / ____|   /\   |  \/  |  ____|
				| |__) | |__) | |  __  | |  __   /  \  | \  / | |__   
				|  _  /|  ___/| | |_ | | | |_ | / /\ \ | |\/| |  __|  
				| | \ \| |    | |__| | | |__| |/ ____ \| |  | | |____ 
				|_|  \_\_|     \_____|  \_____/_/    \_\_|  |_|______| )" << endl;

	cout << R"(
		  __      _____ _______       _____ _______    _____          __  __ ______               
		 /_ |    / ____|__   __|/\   |  __ \__   __|  / ____|   /\   |  \/  |  ____|              
		  | |   | (___    | |  /  \  | |__) | | |    | |  __   /  \  | \  / | |__                 
		  | |    \___ \   | | / /\ \ |  _  /  | |    | | |_ | / /\ \ | |\/| |  __|                
		  | |_   ____) |  | |/ ____ \| | \ \  | |    | |__| |/ ____ \| |  | | |____               
		  |_(_) |_____/   |_/_/    \_\_|  \_\ |_|     \_____/_/    \_\_|  |_|______| 
		  ___      _      ______          _____  ______ _____  ____   ____          _____  _____  
		 |__ \    | |    |  ____|   /\   |  __ \|  ____|  __ \|  _ \ / __ \   /\   |  __ \|  __ \ 
		    ) |   | |    | |__     /  \  | |  | | |__  | |__) | |_) | |  | | /  \  | |__) | |  | |
		   / /    | |    |  __|   / /\ \ | |  | |  __| |  _  /|  _ <| |  | |/ /\ \ |  _  /| |  | |
		  / /_ _  | |____| |____ / ____ \| |__| | |____| | \ \| |_) | |__| / ____ \| | \ \| |__| |
		 |____(_) |______|______/_/    \_\_____/|______|_|  \_\____/ \____/_/    \_\_|  \_\_____/ 	
		  ____     ________   _______ _______                                                     
		 |___ \   |  ____\ \ / /_   _|__   __|                                                    
		   __) |  | |__   \ V /  | |    | |                                                       
		  |__ <   |  __|   > <   | |    | |                                                       
		  ___) |  | |____ / . \ _| |_   | |                                                       
		 |____(_) |______/_/ \_\_____|  |_|                                                       
											                                                         
                                  
 )" << endl;
	input = _getch();


	switch (input) {
	case '1':
		system("cls");
		cout << R"(
  ______       _                                                                              
 |  ____|     | |                                                                             
 | |__   _ __ | |_ ___ _ __   _   _  ___  _   _ _ __   _ __   __ _ _ __ ___   ___             
 |  __| | '_ \| __/ _ \ '__| | | | |/ _ \| | | | '__| | '_ \ / _` | '_ ` _ \ / _ \            
 | |____| | | | ||  __/ |    | |_| | (_) | |_| | |    | | | | (_| | | | | | |  __/  _   _   _ 
 |______|_| |_|\__\___|_|     \__, |\___/ \__,_|_|    |_| |_|\__,_|_| |_| |_|\___| (_) (_) (_)
                               __/ |                                                          
                              |___/                                                           
)";
		cin >> player_name;
		getName(player_name);
		break;
	case '2':
		system("cls");

		_level.printLeaderboard();
		break;

	case '3':
		system("cls");
		cout << R"(
  ______      _ _   _                         
 |  ____|    (_) | (_)                        
 | |__  __  ___| |_ _ _ __   __ _             
 |  __| \ \/ / | __| | '_ \ / _` |            
 | |____ >  <| | |_| | | | | (_| |  _   _   _ 
 |______/_/\_\_|\__|_|_| |_|\__, | (_) (_) (_)
                             __/ |            
                            |___/             
)";
		exit(0);
	default:
		system("cls");
		goto wipe;
	}
	return 0;
}

string GameSystem::getName(string name)
{
	name = player_name;
	return name;
}


int main()	
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution <int> levelGen(1, 5);
	char ranlevel = levelGen(randomEngine);

	string levelNo = to_string(ranlevel);
	string level = "level";
	level.append(levelNo);
	level.append(".txt");

	GameSystem gameSystem(level, 1, 20, 20, 20, 5, 0, 100);
	gameSystem.Menu();

	gameSystem.playGame(player_name);


	return 0;
}