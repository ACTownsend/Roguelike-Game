//dragos
#include "pch.h"
#include "Shop.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Shop::Shop()
{
	_x = 0;
	_y = 0;
}

void Shop::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Shop::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}