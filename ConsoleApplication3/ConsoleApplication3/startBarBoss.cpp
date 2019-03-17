#include "pch.h"
#include "startBarBoss.h"
#include <iostream>



startBarBoss::startBarBoss()
{
	
}
void startBarBoss::abc() {
	start = 15;
	for (int i=0; i<=start; i++)
		cout << "_";
	cout << "" << endl;
	for (int b = 0; b < start; b++) {
		cout << "*";
	}
	cout << "/" << endl;
}

