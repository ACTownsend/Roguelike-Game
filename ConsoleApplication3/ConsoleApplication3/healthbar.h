#pragma once

class healthbar
{
public:
	healthbar();
	void core(int dmg);

	
private:
	int h;
	int start;
	int total = 0;
};

