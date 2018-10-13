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
Continent* parseContinent(std::string line) {
	std::string delimiter = "=";

	int delimiterPos = line.find(delimiter);
	if (delimiterPos == std::string::npos) {
		return NULL;
	}

	std::string name = line.substr(0, delimiterPos);
	int value = std::stoi(line.substr(delimiterPos + 1, std::string::npos));

	return new Continent(name, value);
}

// Creates the Territories via parsing but does not establish neighborhood
Territory* createTerritories(std::string line) {
	std::string delimiter = ",";

	int delimiterPos = line.find(delimiter);
	if (delimiterPos == std::string::npos) {
		return NULL;
	}

	std::string name = line.substr(0, delimiterPos);
	line = line.substr(delimiterPos + 1, std::string::npos);
	delimiterPos = line.find(delimiter);

	return new Territory(name);
}

// Locates a continent from the vector
Continent* findContinent(std::string name) {
	for (Continent* c : continents) {
		if (name == c->getName()) {
			return c;
		}
	}
	return NULL;
}

// Locates a territory from the vector
Territory* findTerritory(std::string name) {
	for (Territory* t : territories) {
		if (name == t->getName()) {
			return t;
		}
	}
	return NULL;
}

// Given the existence of a given territory, does a second apss through to assign it to a continent and its neighbors
void assignTerritory(std::string line) {
	std::string delimiter = ",";
	int delimiterPos = line.find(delimiter);

	std::string terrName = line.substr(0, delimiterPos);
	line = line.substr(delimiterPos + 1, std::string::npos);
	delimiterPos = line.find(delimiter);
	Territory* terr = findTerritory(terrName);

	// Progresses the stream, and techncially verifies even if not used
	int xPos = std::stoi(line.substr(0, delimiterPos));
	line = line.substr(delimiterPos + 1, std::string::npos);
	delimiterPos = line.find(delimiter);
	int yPos = std::stoi(line.substr(0, delimiterPos));
	line = line.substr(delimiterPos + 1, std::string::npos);
	delimiterPos = line.find(delimiter);

	std::string contName = line.substr(0, delimiterPos);
	line = line.substr(delimiterPos + 1, std::string::npos);
	delimiterPos = line.find(delimiter);
	Continent* cont = findContinent(contName);

	std::vector<Territory*> neighbors;
	std::string neighbor;

	while (delimiterPos != std::string::npos) {
		neighbor = line.substr(0, delimiterPos);
		line = line.substr(delimiterPos + 1, std::string::npos);
		delimiterPos = line.find(delimiter);
		terr->addNeighbor(findTerritory(neighbor));
	}

	cont->addTerritory(terr);
}

// Returns the map represented by a .map file
Map* getMap(std::string map) {
	std::ifstream mapFile;
	mapFile.open(map);
	std::string nextLine;

	int mode = 0;
	std::vector<std::string> repeatTerritories;

	while (std::getline(mapFile, nextLine)) {
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
			continents.push_back(parseContinent(nextLine));
			continue;
		}
		// first create territories - neighbors and appropriate continents are done after file is read
		else if (mode == 3) {
			territories.push_back(createTerritories(nextLine));
			repeatTerritories.push_back(nextLine);
		}
	}

	mapFile.close();
	for (std::string line : repeatTerritories) {
		assignTerritory(line);
	}

	Map* worldMap = new Map(continents, territories);

	return worldMap;
}

