
#include <iostream>

#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../PlayerStrategy/Human.h"
#include "Driver.h"

using namespace std;

int driver::human_strategy_driver() {
	Player* p1 = new Player("Mark");
	Player* p2 = new Player("Jason");
	Territory* ca = new Territory("Canada", 5, p1);
	Territory* usa = new Territory("USA", 8, p1);
	Territory* sp = new Territory("Spain", 8, p1);
	Territory* fr = new Territory("France", 7, p1);
	Territory* me = new Territory("Mexico", 3, p2);
	Territory* ger = new Territory("Germany", 8, p2);
	Territory* uk = new Territory("UK", 7, p2);
	Territory* cn = new Territory("China", 10, p2);
	ca->add_neighbor(usa);
	ca->add_neighbor(cn);
	cn->add_neighbor(ca);
	cn->add_neighbor(sp);
	sp->add_neighbor(cn);
	sp->add_neighbor(ger);
	sp->add_neighbor(fr);
	fr->add_neighbor(sp);
	fr->add_neighbor(ger);
	fr->add_neighbor(uk);
	uk->add_neighbor(me);
	uk->add_neighbor(fr);
	me->add_neighbor(usa);
	me->add_neighbor(uk);
	usa->add_neighbor(me);
	usa->add_neighbor(ca);
	usa->add_neighbor(ger);
	ger->add_neighbor(usa);
	ger->add_neighbor(fr);
	ger->add_neighbor(sp);
	ger->add_neighbor(cn);
	p1->add_territory(ca);
	p1->add_territory(usa);
	p1->add_territory(sp);
	p1->add_territory(fr);
	p2->add_territory(me);
	p2->add_territory(ger);
	p2->add_territory(uk);
	p2->add_territory(cn);

	cout << "--------------------------";
	cout << "Testing for 2 players";
	cout << "--------------------------" << endl;
	p1->setStrategy(new Human());
	p1->executeStrategy();
	cout << "---------------------------------------------------" << endl;
	p2->setStrategy(new Human());
	p2->executeStrategy();



	system("PAUSE");
	return 0;
}