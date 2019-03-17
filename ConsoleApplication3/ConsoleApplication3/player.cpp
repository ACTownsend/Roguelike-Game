#include "pch.h"
#include "player.h"
#include <fstream>
#include "GameSystem.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

player::player()
{
}

void player::loadP(string fileName) {
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
void player::printP() {
	for (int i = 0; i < _playerData.size(); i++) {
		printf("%s\n", _playerData[i].c_str());
	}
	printf("\n");
}

void player::core(int dmg, int e)
{
	h = start-dmg;
	if (h > 0 && start>dmg) {

			for (int c = 0; c <= start; c++)
				cout << "_";
			cout << "" << endl;
			for (int d = 0; d < h; d++)
				cout << "*";

			for (int z = 0; z < (start-h); z++)
				cout << " ";
			cout << "/" << endl;		
	}

	else
	{
		cout << "" << endl;
		cout << "## DEAD ##" << endl;
	}


}
void player::core1(int dmg1, int e1){
	h1 = start1 - dmg1;
	if (h1 > 0 && start1 > dmg1) {

		for (int c1 = 0; c1 <= start1; c1++)
			cout << "_";
		cout << "" << endl;
		for (int d1 = 0; d1 < h1; d1++)
			cout << "*";

		for (int z1 = 0; z1 < (start1 - h1); z1++)
			cout << " ";
		cout << "/" << endl;
	}

	else
	{
		cout << "" << endl;
		cout << "## DEAD ##" << endl;
	}



}