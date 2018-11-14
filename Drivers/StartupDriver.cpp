//
// Created by Michael Wu on 2018-11-03.
//

#include "../Phase/Startup.h"
#include "../Map/MapLoader.h"
#include "Driver.h"

// Driver for the startup phase
int driver::startup_driver() {
    // Setup for list of players
    Player playerA;
    playerA.setPID(1);

    Player playerB;
    playerB.setPID(2);

    Player playerC;
    playerC.setPID(3);

    Player playerD;
    playerD.setPID(4);

    vector<Player*> players;
    players.emplace_back(&playerA);
    players.emplace_back(&playerB);
    players.emplace_back(&playerC);
    players.emplace_back(&playerD);

    // Setup for list of territories
    Territory t1("Canada");
    Territory t2("Usa");
    Territory t3("Mexico");
    Territory t4("Russia");
    Territory t5("France");
    Territory t6("United-Kingdom");
    Territory t7("China");
    Territory t8("Spain");
    Territory t9("Italy");
    Territory t10("Japan");
    Territory t11("Egypt");
    Territory t12("Bosnia");

    vector<Territory*> territories;
    territories.emplace_back(&t1);
    territories.emplace_back(&t2);
    territories.emplace_back(&t3);
    territories.emplace_back(&t4);
    territories.emplace_back(&t5);
    territories.emplace_back(&t6);
    territories.emplace_back(&t7);
    territories.emplace_back(&t8);
    territories.emplace_back(&t9);
    territories.emplace_back(&t10);
    territories.emplace_back(&t11);
    territories.emplace_back(&t12);

    Startup::execute_startup_phase(players, territories);

    cout << "***** Results *****" << endl;
    for (auto &player : players) {
        cout << "Player " << player->getPID() << ":" << endl;
        for (auto &territory : player->get_own_territories()) {
            cout << territory->get_name() << " has " << territory->get_troops() << " armies" << endl;
        }
        cout << "\n";
    }
}