#include "pch.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>
#include "GameSystem.h"

using namespace std;

int main() 
{	
	GameSystem gameSystem("bossdesign.txt", "playerdesign.txt");

	gameSystem.playGame();
	
	
	
	
	return 0;
}