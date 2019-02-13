// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <string>



#include "GameSystem.h"

using namespace std;


int GameSystem::Menu()
{
	char input;
	string player_name;

wipe:
	system("cls");
	cout << R"(
				 _____  _____   _____    _____          __  __ ______ 
				|  __ \|  __ \ / ____|  / ____|   /\   |  \/  |  ____|
				| |__) | |__) | |  __  | |  __   /  \  | \  / | |__   
				|  _  /|  ___/| | |_ | | | |_ | / /\ \ | |\/| |  __|  
				| | \ \| |    | |__| | | |__| |/ ____ \| |  | | |____ 
				|_|  \_\_|     \_____|  \_____/_/    \_\_|  |_|______|
 )" << endl;

	cout << R"(
			  _     ____ _____  _    ____ _____    ____    _    __  __ _____ 
			 / |   / ___|_   _|/ \  |  _ \_   _|  / ___|  / \  |  \/  | ____|
			 | |   \___ \ | | / _ \ | |_) || |   | |  _  / _ \ | |\/| |  _|  
			 | |_   ___) || |/ ___ \|  _ < | |   | |_| |/ ___ \| |  | | |___ 
			 |_(_) |____/ |_/_/   \_\_| \_\|_|    \____/_/   \_\_|  |_|_____|
			  ____       ___  ____ _____ ___ ___  _   _
			 |___ \     / _ \|  _ \_   _|_ _/ _ \| \ | |                     
			   __) |   | | | | |_) || |  | | | | |  \| |                     
			  / __/ _  | |_| |  __/ | |  | | |_| | |\  |                     
			 |_____(_)  \___/|_|    |_| |___\___/|_| \_|     
              
                          _____    _____ _  _ ___ _____  
			 |___ /   | ____\ \/ /_ _|_   _|                                 
			   |_ \   |  _|  \  / | |  | |                                   
			  ___) |  | |___ /  \ | |  | |                                   
			 |____(_) |_____/_/\_\___| |_|                                   
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
		break;
	case '2':
		system("cls");
		cout << R"(
 __          __              _____   _____             __  __            _               
 \ \        / /     /\      / ____| |  __ \           |  \/  |          (_)              
  \ \  /\  / /     /  \    | (___   | |  | |  ______  | \  / | _____   ___ _ __   __ _   
   \ \/  \/ /     / /\ \    \___ \  | |  | | |______| | |\/| |/ _ \ \ / / | '_ \ / _` |  
    \  /\  /     / ____ \   ____) | | |__| |          | |  | | (_) \ V /| | | | | (_| |  
     \/  \/     /_/    \_\ |_____/  |_____/           |_|  |_|\___/ \_/ |_|_| |_|\__, |  
  _____        _____  _                              _____       _____ _          __/ |  
 |  __ \      |  __ \| |                            / ____|     / ____| |        |___/   
 | |__) |_____| |__) | | __ _ _   _  ___ _ __      | (___ _____| (___ | |__   ___  _ __  
 |  ___/______|  ___/| |/ _` | | | |/ _ \ '__|      \___ \______\___ \| '_ \ / _ \| '_ \ 
 | |          | |    | | (_| | |_| |  __/ |     _   ____) |     ____) | | | | (_) | |_) |
 |_|          |_|    |_|\__,_|\__, |\___|_|    ( ) |_____/     |_____/|_| |_|\___/| .__/ 
  ______      ______           __/ |           |/     ____        ____            | |    
 |  ____|    |  ____|         |___/                  |  _ \      |  _ \           |_|    
 | |__ ______| |__   _ __   ___ _ __ ___  _   _      | |_) |_____| |_) | ___  ___ ___    
 |  __|______|  __| | '_ \ / _ \ '_ ` _ \| | | |     |  _ <______|  _ < / _ \/ __/ __|   
 | |____     | |____| | | |  __/ | | | | | |_| |  _  | |_) |     | |_) | (_) \__ \__ \   
 |______|    |______|_| |_|\___|_| |_| |_|\__, | ( ) |____/      |____/ \___/|___/___/   
                                           __/ | |/                                      
                                          |___/                                          
  ______      ______ _             _   ____                                              
 |  ____|    |  ____(_)           | | |  _ \                                             
 | |__ ______| |__   _ _ __   __ _| | | |_) | ___  ___ ___                               
 |  __|______|  __| | | '_ \ / _` | | |  _ < / _ \/ __/ __|                              
 | |         | |    | | | | | (_| | | | |_) | (_) \__ \__ \                              
 |_|         |_|    |_|_| |_|\__,_|_| |____/ \___/|___/___/                              
                                                                                         
                                                                                         
)";
		input = _getch();
		switch (input)
		{
		case 8:
			system("cls");
			goto wipe;

		}

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




int main()
{
	
	GameSystem gameSystem("level1.txt");
	gameSystem.Menu();

	gameSystem.playGame();


	return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
