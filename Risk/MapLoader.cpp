// Assignment 1, Part 2: MapLoader
// Written by Michael Luger, 40055539

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "Map.h"
#include "MapLoader.h"

// Parses a Continent from a line
Continent* parse_continent(std::string line) {
	std::string delimiter = "=";

	int delimiter_pos = line.find(delimiter);
	if (delimiter_pos == std::string::npos) {
		return NULL;
	}

	std::string name = line.substr(0, delimiter_pos);
	int value = std::stoi(line.substr(delimiter_pos + 1, std::string::npos));

	return new Continent(name, value);
}

// Creates the Territories via parsing but does not establish neighborhood
Territory* create_territories(std::string line) {
	std::string delimiter = ",";

	int delimiter_pos = line.find(delimiter);
	if (delimiter_pos == std::string::npos) {
		return NULL;
	}

	std::string name = line.substr(0, delimiter_pos);
	line = line.substr(delimiter_pos + 1, std::string::npos);
	delimiter_pos = line.find(delimiter);

	return new Territory(name);
}

// Locates a continent from the vector
Continent* find_continent(std::string name) {
	for (Continent* c : continents) {
		if (name == c->get_name()) {
			return c;
		}
	}
	return NULL;
}

// Locates a territory from the vector
Territory* find_territory(std::string name) {
	for (Territory* t : territories) {
		if (name == t->get_name()) {
			return t;
		}
	}
	return NULL;
}

// Given the existence of a given territory, does a second apss through to assign it to a continent and its neighbors
void assign_territory(std::string line) {
	std::string delimiter = ",";
	int delimiter_pos = line.find(delimiter);

	std::string terrName = line.substr(0, delimiter_pos);
	line = line.substr(delimiter_pos + 1, std::string::npos);
	delimiter_pos = line.find(delimiter);
	Territory* terr = find_territory(terrName);

	// Progresses the stream, and techncially verifies even if not used
	int xPos = std::stoi(line.substr(0, delimiter_pos));
	line = line.substr(delimiter_pos + 1, std::string::npos);
	delimiter_pos = line.find(delimiter);
	int yPos = std::stoi(line.substr(0, delimiter_pos));
	line = line.substr(delimiter_pos + 1, std::string::npos);
	delimiter_pos = line.find(delimiter);

	std::string contName = line.substr(0, delimiter_pos);
	line = line.substr(delimiter_pos + 1, std::string::npos);
	delimiter_pos = line.find(delimiter);
	Continent* cont = find_continent(contName);

	std::vector<Territory*> neighbors;
	std::string neighbor;

	while (delimiter_pos != std::string::npos) {
		neighbor = line.substr(0, delimiter_pos);
		line = line.substr(delimiter_pos + 1, std::string::npos);
		delimiter_pos = line.find(delimiter);
		terr->add_neighbor(find_territory(neighbor));
	}

	cont->add_territory(terr);
}

// Returns the map represented by a .map file
Map* get_map(std::string map) {
	std::ifstream map_file;
	map_file.open(map);
	std::string nextLine;

	int mode = 0;
	std::vector<std::string> repeat_territories;

	while (std::getline(map_file, nextLine)) {
		// Skip empty lines because getline doesn't like those
		if (nextLine.compare("") == 0) {
			continue;
		}
		// Determine whether currently looking at settings, continents, or territories (matching with optional whitespace)
		if (nextLine.compare("[Map]") == 0) {
			mode = 1;
			continue;
		}
		else if (nextLine.compare("[Continents]") == 0) {
			mode = 2;
			continue;
		}
		else if (nextLine.compare("[Territories]") == 0) {
			mode = 3;
			continue;
		}

		// ignore settings
		if (mode == 1) {
			continue;
		}
		// add new continents
		else if (mode == 2) {
			continents.push_back(parse_continent(nextLine));
			continue;
		}
		// first create territories - neighbors and appropriate continents are done after file is read
		else if (mode == 3) {
			territories.push_back(create_territories(nextLine));
			repeat_territories.push_back(nextLine);
		}
	}

	map_file.close();
	for (std::string line : repeat_territories) {
		assign_territory(line);
	}

	Map* world_map = new Map(continents, territories);

	return world_map;
}

