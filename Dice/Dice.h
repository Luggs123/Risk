#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Dice {
public:
	std::string name;
	Dice();
	Dice(std::string nam);
	int totalRolled;
	int currentResult[3];
	int diceStats[7];
	void getPercentage();
	void roll(int num);
	void game();
	void sortResult();
};