
#include "../Map/MapLoader.h"
#include "../Deck/Deck.h"
#include "../Dice/Dice.h"
#include "../Player/Player.h"

#include "../Phase/Fortification.h"
#include "Driver.h"

using namespace std;

int driver::fortification_driver() {
    std::string mapFile;
    mapFile = "./MapTemplates/World.map";
    MapLoader ml;
    Map* worldMap = ml.get_map(mapFile);//load a map
    cout << "default map loaded." << endl << endl;
    int num_territory = worldMap->territories.size();

    Player* P = new Player("PLAYER1");//create a player
    cout << "Sample player created" << endl << endl;

    int owned;
    bool t = true;
    do {
        cout << "Please select the number of territories sample player owned" << endl
             << "from 1 to " << num_territory << endl;

        cin >> owned;
        if (owned > 0 && owned < num_territory)
            t = false;
        else
            cout << "invalid input. Please choose one again." << endl;
    } while (t);

    for (int i = 0; i < owned; i++) {
        P->add_territory(worldMap->territories[i]);
        //worldMap->territories[i]->set_owner(P);
        //(P->get_controlled()+i)->set_troops(8);
		(P->get_own_territories())[i]->set_troops(8);
    }
    int c = 3;
    do {
        cout<<endl<<endl<<"------------------------------------------------------" <<endl
            << "Please select the function to run. 2 for fortification. 0 to exit" << endl;
        cin >> c;
        switch(c) {
            case 0:
                break;
            case 2:
                cout << "calling fortification" << endl;
                Fortification(*P).fortificate();
                break;
            default:
                cout << "invalid input, please choose again" << endl;
        }

    } while (c != 0);



    cout << "Driver ended" << endl;
    system("PAUSE");
    return 0;
}