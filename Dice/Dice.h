#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Dice {
public:
	std::string name;
	Dice();
	Dice(std::string nam);
	int totalRolled;
	int currentRolled;
	int currentResult[3];
	int diceStats[7];
	void getPercentage();
	void roll(int num);
	void game();
	void sortResult();
};