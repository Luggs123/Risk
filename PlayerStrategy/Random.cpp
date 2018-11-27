#include <iostream>
#include "../Player/Player.h"
#include "Random.h"


void Random::execute(Player* p) {
	cout << "************************Random strategy executed.**************************" << endl;
	cout << "Random Player " << p->getId() << " now own the following:" << endl;
	p->showTerritory();
	cout <<endl<< "------------------------------------------------" << endl;
	p->reinforceRandom();
	cout << "------------------------------------------------" << endl;
	p->attackRandom();
	p->fotifyRandom();
	cout << "------------------------------------------------" << endl;

}
