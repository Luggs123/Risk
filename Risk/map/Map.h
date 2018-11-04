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
	int troops = 0;
	std::vector<Territory*> neighbors;

public:
	// Constructor
	Territory(std::string name);

	// Accessors
	int getTroops();
	std::string getName();
	std::vector<Territory*> getNeightbors();
	//Player* Territory::getOwner();

	// Mutators
	void setTroops(int troops);
	void addNeighbor(Territory* t);
	//void Territory::setOwner(Player* owner);

	// Service Methods
	bool equals(Territory* t);
};

// Defines a continent of territories
class Continent {
private:
	std::string name;
	int value;
	std::vector<Territory*> territories;

public:
	// Constructor
	Continent(std::string name, int value, std::vector<Territory*> territories);
	Continent(std::string name, int value);

	// Accessors
	int getValue();
	std::string getName();
	std::vector<Territory*> getTerritories();

	// Mutators
	void addTerritory(Territory* t);

	// Service Methods
	bool equals(Continent* c);
	bool isConnected();
	void traverse(int iter, std::vector<bool>& conn, Territory* active);
	int indexTerritory(Territory* t);
};

// Defines the entirety of the map
class Map {
public:
	std::vector<Continent*> continents;
	std::vector<Territory*> territories;

	// Constructor
	Map(std::vector<Continent*> continents, std::vector<Territory*> territories);

	// Mutators
	void addContinent(Continent* c);

	// Service Methods
	bool isConnected();
	void traverse(int iter, std::vector<bool>& conn, Territory* active);
	int indexTerritory(Territory* t);
};
#endif
