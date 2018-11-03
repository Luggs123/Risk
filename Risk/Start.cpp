// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

using namespace std;

#include <iostream>
#include <string>
#include "../Map/MapLoader.h"
#include "Payload.h"

Payload start() {
	string path;
	cout << "Please select a .map file to be used for this game." << endl;
	cin >> path;

	Map game_map = *get_map(path);

	int players;
	cout << "How many players will be participating? (2-6)" << endl;
	while (true) {
		try {
			string pl;
			cin >> pl;
			players = stoi(pl);
			if (players < 2 || players > 6) {
				cout << "That is not a valid amount of players. Please try again." << endl;
			}
			else {
				break;
			}
		}
		catch (invalid_argument) {
			cout << "That is not a number. Please try again." << endl;
		}
	}

	vector<Player*>* playerVector = new vector<Player*>();
	for (int i = 0; i < players; i++) {
		playerVector->push_back(new Player(i + 1));
	}

	vector<string>* territories = new vector<string>();
	for (Territory* t : game_map.territories) {
		territories->push_back(t->get_name());
	}

	Deck* deck = new Deck(*territories);

	return *(new Payload(game_map, *playerVector, *deck));
}