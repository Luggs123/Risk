#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "Map.h"

namespace {
	std::vector<Territory*> territories;
	std::vector<Continent*> continents;
}

Continent* parseContinent(std::string line);
Territory* createTerritories(std::string line);
Continent* findContinent(std::string name);
Territory* findTerritory(std::string name);
void assignTerritory(std::string line);
Map* getMap(std::string map);

#endif