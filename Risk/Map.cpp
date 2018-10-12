// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#include <vector>
#include <string>
#include <iostream>
#include "Map.h"

// ================== TERRITORY ==================
// Constructor
Territory::Territory(std::string name) {
	this->name = name;
}

// Accessors
int Territory::getTroops() {
	return this->troops;
}

std::string Territory::getName() {
	return this->name;
}

std::vector<Territory> Territory::getNeightbors() {
	return this->neighbors;
}

//Player* Territory::getOwner() {
//	return this->owner;
//}

// Mutators
void Territory::setTroops(int troops) {
	this->troops = troops;
}

void Territory::addNeighbor(Territory t) {
	this->neighbors.push_back(t);
}

//void Territory::setOwner(Player* owner) {
//	this->owner = owner;
//}

// Service Methods
bool Territory::equals(Territory t) {
	return this->name == t.name;
}

// ================== CONTINENT ==================
// Constructor
Continent::Continent(std::string name, int value, std::vector<Territory> territories) {
	this->name = name;
	this->value = value;
	this->territories = territories;
}

// Accessors
int Continent::getValue() {
	return this->value;
}

std::string Continent::getName() {
	return this->name;
}

std::vector<Territory> Continent::getTerritories() {
	return this->territories;
}

// Service Methods
// Determines the connectivity of the continent
bool Continent::isConnected() {
	int countTerritories = territories.size();
	std::vector<bool> isConnected;
	for (Territory t : territories) {
		isConnected.push_back(false);
	}

	// Traverses the graph the worst-case number of iterations, being the number of territories
	traverse(countTerritories - 1, isConnected, this->getTerritories().front());
	for (bool b : isConnected) {
		std::cout << b;
	}
	for (bool b : isConnected) {
		if (b == false) {
			return false;
		}
	}
	return true;
}

// Traverses between unvisited neighbors of the active territory recursively
void Continent::traverse(int iter, std::vector<bool>& conn, Territory active) {
	conn.at(indexTerritory(active)) = true; // Marks active territory as visited
	std::cout << active.getName() << indexTerritory(active) << std::endl;
	// Base case: final iteration, finishes the recursive call
	if (iter == 0) {
		return;
	}
	// Recursive case: traverse all unvisited continent neighbors of the active territory, then finish the call
	else {
		for (Territory t : active.getNeightbors()) {
			if (indexTerritory(t) != -1 && conn.at(indexTerritory(t) == false)) {
				traverse(iter - 1, conn, t);
			}
		}
		return;
	}
}

// Gets the index of a territory in the territories vector, -1 if not in this continent
int Continent::indexTerritory(Territory t) {
	for (int i = 0; i < this->territories.size(); i++) {
		if (this->territories.at(i).equals(t)) {
			return i;
		}
	}
	return -1;
}

// Defines the entirety of the map
// ================== MAP ==================
std::vector<Continent> continents;
std::vector<Territory> territories;

// Constructor
Map::Map(std::vector<Continent> continents, std::vector<Territory> territories) {
	this->continents = continents;
	this->territories = territories;
}

// Service Methods
// Determines the connectivity of the Map
bool Map::isConnected() {
	int countTerritories = territories.size();
	std::vector<bool> isConnected;
	for (Territory t : territories) {
		isConnected.push_back(false);
	}

	// Traverses the graph the worst-case number of iterations, being the number of territories
	traverse(countTerritories - 1, isConnected, territories.front());
	for (bool b : isConnected) {
		std::cout << b;
	}
	for (bool b : isConnected) {
		if (b == false) {
			return false;
		}
	}
	return true;
}

// Traverses between unvisited neighbors of the active territory recursively
void Map::traverse(int iter, std::vector<bool>& conn, Territory active) {
	conn.at(indexTerritory(active)) = true; // Marks active territory as visited
	std::cout << active.getName() << indexTerritory(active) << std::endl;
	// Base case: final iteration, finishes the recursive call
	if (iter == 0) {
		return;
	}
	// Recursive case: traverse all unvisited continent neighbors of the active territory, then finish the call
	else {
		for (Territory t : active.getNeightbors()) {
			if (conn.at(indexTerritory(t) == false && indexTerritory(t) != -1)) {
				traverse(iter - 1, conn, t);
			}
		}
		return;
	}
}

// Gets the index of a territory in the territories vector, -1 if not placed on the map
int Map::indexTerritory(Territory t) {
	for (int i = 0; i < this->territories.size(); i++) {
		if (this->territories.at(i).equals(t)) {
			return i;
		}
	}
	return -1; 
}