//
// Created by Michael Wu on 2018-11-03.
//

#include "../Phase/Game.h"
#include "Driver.h"

// driver for the main game loop
int driver::main_game_driver()
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
    Player playerA("1");
    playerA.add_territory(&t1);
    playerA.add_territory(&t2);
    playerA.add_territory(&t3);

    Player playerB("2");
    playerB.add_territory(&t4);
    playerB.add_territory(&t5);
    playerB.add_territory(&t6);

    Player playerC("3");
    playerC.add_territory(&t7);
    playerC.add_territory(&t8);
    playerC.add_territory(&t9);

    Player playerD("4");
    playerD.add_territory(&t10);
    playerD.add_territory(&t11);
    playerD.add_territory(&t12);

    vector<Player*> players;
    players.emplace_back(&playerA);
    players.emplace_back(&playerB);
    players.emplace_back(&playerC);
    players.emplace_back(&playerD);

    cout << "***** Before main game loop *****" << endl;
    for (auto &player : players) {
        cout << "Player " << player->getPID() << endl;
        player->show_territory();
        cout << "\n";
    }
    cout << "\n";

    cout << "***** Main game loop *****" << endl;
    Game::execute_main_game_loop(players, territories, true);
    cout << "\n";

    cout << "***** After main game loop *****" << endl;
    for (auto &player : players) {
        cout << "Player " << player->getPID() << endl;
        player->show_territory();
        cout << "\n";
    }
}