#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>

GameSystem::GameSystem(string bossFile, string playerFile) {

	_boss.load(bossFile);
	_boss.print();
	cout << "" << endl;
	_boss.abc();
	_player.loadP(playerFile);
	_player.printP();
	_boss.abc();
	while (true) {
		int a = dmg;
		cin >> e;
		dmg = e + a;
		system("cls");
		_boss.print();
		cout << "" << endl; 
		_player.core(dmg, e);
		

		int a1 = dmg1;
		static default_random_engine randomEngine(time(NULL));
		uniform_int_distribution <int> attackRoll(1, bossDmg);
		e1 = attackRoll(randomEngine);
		dmg1 = e1 + a1;
		_player.printP();
		_player.core1(dmg1, e1);
}
		system("PAUSE");
	
}

void GameSystem::playGame() {

}
