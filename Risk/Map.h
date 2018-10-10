// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

// Defines an individual territory on the map
class Territory {
private:
	//Player* owner;
	std::string name;
	int troops;
	std::vector<Territory> neighbors;

public:
	// Constructor
	Territory::Territory(std::string name);

	// Accessors
	int Territory::getTroops();
	std::string Territory::getName();
	std::vector<Territory> Territory::getNeightbors();
	//Player* Territory::getOwner();

	// Mutators
	void Territory::setTroops(int troops);
	void Territory::addNeighbor(Territory t);
	//void Territory::setOwner(Player* owner);

	// Service Methods
	bool Territory::equals(Territory t);
};

// Defines a continent of territories
class Continent {
private:
	std::string name;
	int value;
	std::vector<Territory> territories;

public:
	// Constructor
	Continent::Continent(std::string name, int value, std::vector<Territory> territories);

	// Accessors
	int Continent::getValue();
	std::string Continent::getName();
	std::vector<Territory> Continent::getTerritories();

	// Service Methods
	bool Continent::isConnected();
	void Continent::traverse(int iter, std::vector<bool> conn, Territory active);
	int Continent::indexTerritory(Territory t);
};

// Defines the entirety of the map
class Map {
	std::vector<Continent> continents;
	std::vector<Territory> territories;

	// Constructor
	Map::Map(std::vector<Continent> continents, std::vector<Territory> territories);

	// Service Methods
	bool Map::isConnected();
	void Map::traverse(int iter, std::vector<bool> conn, Territory active);
	int Map::indexTerritory(Territory t);
};
#endif
