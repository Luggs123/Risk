// Assignment 1, Part 2: MapLoader (Driver)
// Written by Michael Luger, 40055539

#include <iostream>
#include <string>
#include "../Map/Map.h"
#include "../Map/MapLoader.h"

using namespace std;

int main() {
	string map_file;
	map_file = "World.map";
	Map* world_map = get_map(map_file);
	
	// Neighbor List
	//for (Continent* c : world_map->continents) {
	//	cout << c->get_name() << ": " << endl;
	//	for (Territory* t : c->get_territories()) {
	//		cout << t->get_name() << ": ";
	//		for (Territory* n : t->get_neighbors()) {
	//			cout << n->get_name() << ", ";
	//		}
	//		cout << endl;
	//	}
	//}

	// Connectivity
	for (Continent* c : world_map->continents) {
		cout << c->get_name() << " " << c->is_connected() << endl;
	}
	cout << world_map->is_connected();
}