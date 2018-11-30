// Assignment 4 by Ma,Ke.

#include <iostream>
#include "../Player/Player.h"
#include "Random.h"


void Random::execute(Player* p) {
	cout << "************************Random strategy executed.**************************" << endl;
	cout << "Random Player " << p->getPID() << " now own the following:" << endl;
	p->show_territory();
	cout <<endl<< "------------------------------------------------" << endl;
	p->reinforceRandom();
	cout << "------------------------------------------------" << endl;
	p->attackRandom();
	p->fotifyRandom();
	cout << "------------------------------------------------" << endl;

}