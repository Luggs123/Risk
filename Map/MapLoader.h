#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#include "Map.h"

class MapLoader {
private:
	std::vector<Territory*> territories;
	std::vector<Continent*> continents;

public:
	Continent* parse_continent(std::string line);
	Territory* create_territories(std::string line);
	Continent* find_continent(std::string name);
	Territory* find_territory(std::string name);
	void assign_territory(std::string line);
	Map* get_map(std::string map);
};

#endif