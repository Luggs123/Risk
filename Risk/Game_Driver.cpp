//
// Created by Michael Wu on 2018-11-03.
//

#include "Game.h"

int main()
{
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

    // Setup for list of players
    Player playerA;
    playerA.setPID(1);
    playerA.addTerritory(t1);
    playerA.addTerritory(t2);
    playerA.addTerritory(t3);

    Player playerB;
    playerB.setPID(2);
    playerB.addTerritory(t4);
    playerB.addTerritory(t5);
    playerB.addTerritory(t6);

    Player playerC;
    playerC.setPID(3);
    playerC.addTerritory(t7);
    playerC.addTerritory(t8);
    playerC.addTerritory(t9);

    Player playerD;
    playerD.setPID(4);
    playerD.addTerritory(t10);
    playerD.addTerritory(t11);
    playerD.addTerritory(t12);

    vector<Player*> players;
    players.emplace_back(&playerA);
    players.emplace_back(&playerB);
    players.emplace_back(&playerC);
    players.emplace_back(&playerD);

    cout << "***** Before main game loop *****" << endl;
    for (auto &player : players) {
        cout << "Player " << player->getPID() << endl;
        player->showTerritory();
        cout << "\n";
    }
    cout << "\n";

    cout << "***** Main game loop *****" << endl;
    Game::execute_main_game_loop(players, territories, true);
    cout << "\n";

    cout << "***** After main game loop *****" << endl;
    for (auto &player : players) {
        cout << "Player " << player->getPID() << endl;
        player->showTerritory();
        cout << "\n";
    }
}