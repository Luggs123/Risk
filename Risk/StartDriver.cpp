// Assignment 2, Part 1: Game Start (Driver)
// Written by Michael Luger, 40055539

using namespace std;

#include "Start.h"

int main() {
	// The World map is connected and valid.
	Payload* world_game = start("World.map", 3); 
	// Europe's file has been modified to be disconnected only in UK and Ireland, and is thus invalid. It will return null.
	Payload* europe_game = start("Europe.map", 6);

	//try {
	//	Map test_map = europe_game->get_map();
	//}
	//catch (...) {
	//	cout << "europe_game was invalid and thus returned and empty Payload.";
	//}

	cout << "world_game has created " << world_game->get_players().size() << " players, and " << world_game->get_deck().getDeckSize()
		<< " cards." << endl;

	cout << "Trying to do anything with europe_game pretty much just breaks everything." << endl;
}