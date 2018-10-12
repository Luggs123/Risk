#include "dice.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {
	cout << "------------------------------" << endl;
	cout << "         Dice Rolling         " << endl;
	cout << "------------------------------" << endl;


	dice *player[3];
	for (int i = 0; i < 3; i++) {
		cout << "Please enter the name for player" << (i + 1) << "." << endl;
		string tempName;
		cin >> tempName;
		player[i]= new dice();
	}
	cout << endl;
	
	int userChoice = 0;

	while (userChoice != 2)
	{
		cout << "Please choose one of the following options:" << endl;
		cout << "1. play." << endl;
		cout << "2. stop and exit." << endl;
		cin >> userChoice;
		cout << endl;
		switch (userChoice)
		{
		case 1: {
			int playerNum;
			cout << "Enter the player's number to continue.(1 to 3)" << endl;
			cin >> playerNum; cout << endl;
			if ((playerNum >=1)&&(playerNum<=3)) player[playerNum-1]->game();
			else cerr << "invalid player's number entered, back to main menu.\n" << endl;
			break;
		}
		case 2: break;
		default:	cerr << "Please enter a valid number (1 or 2).\n"; cout <<endl; break;
		}
	}


	return 0;

}