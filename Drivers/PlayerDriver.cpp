#include "../Player/Player.h"
#include "Driver.h"

using namespace std;

int driver::player_driver() {
    cout << "This is the test Driver of Assignment1, Part4: Player, For group 21.\n"
         <<"------------------------------------------\n"
         <<"creating players\n" <<endl;
    vector<Player> Players;
    Player *t;
    vector<string> s;
    Territory *tempt;

    for (unsigned int i = 0; i < 5;i++) {
        t = new Player();
        string pid = "player_" + to_string(i);
        t->setPID(pid);
        Players.push_back(*t);
    }
    cout << "Displaying Player ID" << endl;
    cout << Players[3].getPID() << "\n" << endl;

    cout << "You are going to attack" << endl;
    Players[2].attackroll();
    cout << "calling a round for a player" << endl;
    Players[1].round();

    cout << "\nadding terrotories to a player" << endl;
    for (unsigned int i = 0; i < 5; i++) {
        s.push_back( "Territory No." + std::to_string(i));
        tempt = new Territory(s[i]);
        Players[1].add_territory(tempt);
    }

    cout << "Player1 now owned 5 territories. Displaying names :" << endl;
    Players[1].show_territory();
    cout << "\n-----------------------\n" << endl;

    Players[1].showcardsonHand();

    cout << endl;
    system("PAUSE");
    return 0;
}