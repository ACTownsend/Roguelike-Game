//dragos
#pragma once
#include <string>
using namespace std;
class Shop
{
public:
	Shop();
	void setPosition(int x, int y);

	void getPosition(int &x, int &y);
private:
	int _x;
	int _y;
};