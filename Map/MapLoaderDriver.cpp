// Assignment 1, Part 2: MapLoader (Driver)
// Written by Michael Luger, 40055539

#include <iostream>
#include <string>
#include "Map.h"
#include "MapLoader.h"

int main() {
	std::string map_file;
	map_file = "World.map";
	Map* world_map = get_map(map_file);

	for (Continent* c : world_map->continents) {
		std::cout << c->get_name() << ": " << std::endl;
		for (Territory* t : c->get_territories()) {
			std::cout << t->get_name() << ", ";
		}
		std::cout << c->is_connected() << std::endl;
	}

	std::cout << "Map: " << world_map->is_connected();
}