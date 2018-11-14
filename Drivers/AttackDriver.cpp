
#include <iostream>
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "Driver.h"

using namespace std;

//TODO: contructor used in this driver is inconsistent with the constructors in the Player and Territory. NEED TO SORT THIS OUT
int driver::attack_driver() {
    /*
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
    ca->addNeighbor(usa);
    ca->addNeighbor(cn);
    cn->addNeighbor(ca);
    cn->addNeighbor(sp);
    sp->addNeighbor(cn);
    sp->addNeighbor(ger);
    sp->addNeighbor(fr);
    fr->addNeighbor(sp);
    fr->addNeighbor(ger);
    fr->addNeighbor(uk);
    uk->addNeighbor(me);
    uk->addNeighbor(fr);
    me->addNeighbor(usa);
    me->addNeighbor(uk);
    usa->addNeighbor(me);
    usa->addNeighbor(ca);
    usa->addNeighbor(ger);
    ger->addNeighbor(usa);
    ger->addNeighbor(fr);
    ger->addNeighbor(sp);
    ger->addNeighbor(cn);
    p1->addTerritory(ca);
    p1->addTerritory(usa);
    p1->addTerritory(sp);
    p1->addTerritory(fr);
    p2->addTerritory(me);
    p2->addTerritory(ger);
    p2->addTerritory(uk);
    p2->addTerritory(cn);


    cout << "Testing for 2 players." << endl;

    int menu = 0;
    while (menu!=3) {
        cout << endl<<"Main Menu"<<endl;
        cout << "1.start war." << endl << "2.moving armies." << endl<< "3.exit."<<endl;
        cin >> menu;
        if (menu == 3) break;
        if ((menu > 3) || (menu < 1)) { cout << "invalid option,back to main menu."<< endl; continue; }
        if (menu == 1) {
            cout << "choose the attacker (enter 1 or 2)"<<endl;
            int attacker;
            cin >> attacker; cout << endl;
            switch (attacker)
            {
                case 1: p1->attack(); break;
                case 2: p2->attack(); break;
                default:
                    cout << "invalid player number."<<endl;

                    continue;
            }

        }
        if (menu == 2) {
            for(;;) {
                cout << "Choose a player (1 or 2)"<<endl;
                int pn;
                cin >> pn;
                if ((pn > 2) || (pn < 1)) { cout << "invalid number.." << endl; }
                if (pn == 1) p1->movingArmy();
                if (pn == 2) p2->movingArmy();
                break;
            }


        }





    }

*/
    return 0;
}