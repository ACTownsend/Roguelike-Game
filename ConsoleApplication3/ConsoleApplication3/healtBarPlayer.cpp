#include "pch.h"
#include "healtBarPlayer.h"
#include "GameSystem.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;

healtBarPlayer::healtBarPlayer()
{
}

void healtBarPlayer::core1()
{
	start = 15;
	h = start;

	if (h > 0) {
		static default_random_engine randomEngine(time(NULL));
		uniform_int_distribution <int> attackRoll(1, 5);
		int dmg = attackRoll(randomEngine);

		total = total + dmg;
		h = h - dmg;
		if (dmg < h){
			for (int c = 0; c <= start; c++)
				cout << "_";
		cout << "" << endl;
		for (int d = 0; d < h; d++)
			cout << "*";
		
			for (int z = 0; z < total; z++)
				cout << " ";
			cout << "/" << endl;
		}
	}
	else
	{
		cout << "you killed him good job no one cares" << endl;
	}


}

