#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class dice {

public:
	string name;
	dice();
	dice(string nam);
	int totalRolled;
	int currentResult[3];
	int diceStats[7];
	void getPercentage();
	void roll(int num);
	void game();
};