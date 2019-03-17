#include "pch.h"
#include "boss.h"
#include <fstream>
#include <iostream>


boss::boss()
{
}

void boss::load(string fileName) {
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
void boss::print() {
	for (int i = 0; i < _bossData.size(); i++) {
		printf("%s\n", _bossData[i].c_str());
	}
	printf("\n");
}

void boss::abc() {
	start = 15;
	for (int i = 0; i <= start; i++)
		cout << "_";
	cout << "" << endl;
	for (int b = 0; b < start; b++) {
		cout << "*";
	}
	cout << "/" << endl;
}