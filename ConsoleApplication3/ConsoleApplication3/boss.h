#pragma once
#include<vector>
#include <string>
using namespace std;
class boss
{
public:
	boss();
	void abc();
	void load(string bossFileName);
	void print();
private:
	vector < string > _bossData;
	int start;
};

