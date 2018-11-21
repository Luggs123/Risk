#include "Driver.h"
#include "../Map/MapLoader.h"
#include "../Deck/Deck.h"
#include "../Phase/Reinforcement.h"
#include "../Player/Player.h"
#include "../GameStaticsObserver/GameStaticsView.h"


using namespace std;

int driver::game_statics_observer_driver() {
	std::string mapFile;
	mapFile = "../MapTemplates/World.map";
	MapLoader ml;
	Map* worldMap = ml.get_map(mapFile);//load a map
	cout << "default map loaded." << endl << endl;
	int num_territory = worldMap->territories.size();

	vector<Player*> Players;
	for (int i = 0; i < 3; i++) {
		Players.push_back(new Player("Player No."+std::to_string(i+1)));
		
	}//creating players
	cout << "Three default players created." << endl << endl;

	for (int i = 0; i < worldMap->territories.size(); i++) {

		
		if (i > 1)
			Players[2]->add_territory(worldMap->territories[i]);
		else
			if (i == 0)
				Players[0]->add_territory(worldMap->territories[0]);
			else
				if (i == 1)
					Players[1]->add_territory(worldMap->territories[1]);
	}//assigning territories
	cout << "Territory ownership assigned" << endl << endl;

	//connecting view 
	GameStaticsView *View = new GameStaticsView(worldMap);
	cout << "View connected" << endl << endl;

	cout << "---------------------------------------------------" << endl
		<< "Ready to demonstrate Game Statics Observer" << endl
		<< "----------------------------------------------------" << endl;

	cout << "Player" << Players[0]->getPID() << " is occuping Territory " << worldMap->territories[5]->get_name() << endl
		<< "----------------------------------------------------------------------------------------------------------" << endl << endl;

	worldMap->territories[5]->get_owner()->lose_territory(worldMap->territories[5]);
	Players[0]->add_territory(worldMap->territories[5]);

	cout << endl << endl
		<< "Player " << Players[2]->getPID() << " is occuping Territory " << worldMap->territories[1]->get_name() << ". Which is the only territory owned by Player " << Players[1]->getPID() << endl
		<< "----------------------------------------------------------------------------------------------------------" << endl << endl;
	worldMap->territories[1]->get_owner()->lose_territory(worldMap->territories[1]);
	Players[2]->add_territory(worldMap->territories[1]);
	cout << endl
		<< "Player " << Players[1] << " has been removed" << endl;

	cout << endl << endl
		<< "Player " << Players[2]->getPID() << " is occuping Territory " << worldMap->territories[0]->get_name()  << endl
		<< "----------------------------------------------------------------------------------------------------------" << endl << endl;
	worldMap->territories[0]->get_owner()->lose_territory(worldMap->territories[0]);
	Players[2]->add_territory(worldMap->territories[0]);

	cout << endl << endl
		<< "Player " << Players[2]->getPID() << " is occuping Territory " << worldMap->territories[5]->get_name() << ". Which is the only territory owned by Player " << Players[0]->getPID() << endl
		<< "Player " << Players[0]->getPID() << " will be removed. Player " << Players[2]->getPID() << " will win" << endl
		<< "----------------------------------------------------------------------------------------------------------" << endl << endl;
	worldMap->territories[5]->get_owner()->lose_territory(worldMap->territories[5]);
	Players[2]->add_territory(worldMap->territories[5]);
	cout << endl
		<< "Player " << Players[0]->getPID() << " has been removed. Player " << Players[2]->getPID() <<" is the winner" << endl;

	system("PAUSE");
	return 0;
}

