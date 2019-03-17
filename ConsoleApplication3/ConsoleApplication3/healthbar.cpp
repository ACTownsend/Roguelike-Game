#include "pch.h"
#include "healthbar.h"
#include <iostream>

using namespace std;

healthbar::healthbar()
{
}

void healthbar::core(int dmg)
{
	start = 15;
	h = start;

	if(h > 0) {
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

