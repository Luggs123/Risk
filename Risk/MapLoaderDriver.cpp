// Assignment 1, Part 2: MapLoader (Driver)
// Written by Michael Luger, 40055539

#include <iostream>
#include <string>
#include "Map.h"
#include "MapLoader.h"

int main() {
	std::string mapFile;
	mapFile = "World.map";
	Map* worldMap = getMap(mapFile);

	for (Continent* c : worldMap->continents) {
		std::cout << c->getName() << ": " << std::endl;
		for (Territory* t : c->getTerritories()) {
			std::cout << t->getName() << ": ";
			for (Territory* n : t->getNeightbors()) {
				std::cout << n->getName() << ", ";
			}
		}
	}
}