// Assignment 3, Part 1: Aggressive Player Strategy
// Written by Michael Luger, 40055539

#include <iostream>
#include "../Player/Player.h"
#include "Aggressive.h"

using namespace std;

void Aggressive::execute(Player* p) {
	cout << "Aggressive strategy executed." << endl;
	cout << "Player " << p->getPID() << " currently owns the following:" << endl;
	cout << "Count: " << p->get_own_territories().size() << endl;
	p->show_territory();
	cout << endl;
	p->reinforce_strongest();
	p->attack_with_strongest();
	p->fortify_strongest();
	cout << "Count: " << p->get_own_territories().size() << endl;
}