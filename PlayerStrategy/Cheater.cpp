// Assignment 4, Part 1: Cheater Player Strategy
// Written by Michael Luger, 40055539

#include <iostream>
#include "../Player/Player.h"
#include "Cheater.h"

using namespace std;

void Cheater::execute(Player* p) {
	cout << "Cheater strategy executed." << endl;
	cout << "Player " << p->getPID() << " currently owns the following:" << endl;
	p->show_territory();
	cout << endl;
	p->cheat_reinforce();
	p->cheat_attack();
	p->cheat_fortify();
}