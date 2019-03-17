#pragma once
#include<vector>
#include<string>
using namespace std;
class player
{
public:
	player();
	void loadP(string playerFileName);
	void printP();
	void core(int dmg, int e);
	void core1(int dmg1, int e1);
private:
	vector <string> _playerData;
	int h;
	int start=15;
	int h1;
	int start1=15;


};

