#include <iostream>
#include "dice.h"
#include <string>
#include <iomanip>


dice::dice()
{

	name = "Anonymous player";
	totalRolled = 0;
	diceStats[1] = 0;
	diceStats[2] = 0;
	diceStats[3] = 0;
	diceStats[4] = 0;
	diceStats[5] = 0;
	diceStats[6] = 0;
	currentResult[0] = 0;
	currentResult[1] = 0;
	currentResult[2] = 0;
}

dice::dice(string nam) {
		name = nam;
		totalRolled = 0;
		diceStats[1] = 0;
		diceStats[2] = 0;
		diceStats[3] = 0;
		diceStats[4] = 0;
		diceStats[5] = 0;
		diceStats[6] = 0;
		currentResult[0] = 0;
		currentResult[1] = 0;
		currentResult[2] = 0;
	};

	void dice::getPercentage() {
		cout << fixed << setprecision(2);
		cout << "Percentage for " << name << ":" << endl;
		for (int i = 1; i <= 6; i++) {
			double temp = ((double)diceStats[i] / (double)totalRolled) * 100;
			cout << i << ": " << temp << "%" << endl;
		}

	};
	void dice::roll(int num)
	{
		for (int i = 0; i < 3; i++) currentResult[i] = 0;
		cout << "result:" << endl;
		for (int i = 0; i < num; i++) {
			int temp = (rand() % 6) + 1;
			cout << temp << " ";
			currentResult[i] = temp;
			diceStats[temp] += 1;
		}
		cout << endl;
	};
	void dice::game() {
		cout << "Hello player " << name << ", how many dice you want to roll ? (from 1 to 3)" << endl;
		int numOfdice;
		cin >> numOfdice; cout << endl;
		if ((numOfdice >= 1) && (numOfdice <= 3))
		{
			totalRolled += numOfdice;
			roll(numOfdice);
			getPercentage();
		}
		else cerr << "invalid number of dice entered, back to main menu.\n"; cout << endl;

	}
