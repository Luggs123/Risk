// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#include <string>

// Defines an individual territory on a map
class Territory {
private:
	// Player* owner;
	std::string name;
	int troops;
	Territory *neighbors [];

public:
	// Constructor
	Territory(std::string name) {
		this->name = name;
	}

	// Accessors
	int Territory::getTroops() {
		return this->troops;
	}

	std::string Territory::getName() {
		return this->name;
	}

	//Player* Territory::getOwner() {
	//	return this->owner;
	//}

	// Mutators
	void Territory::setTroops(int troops) {
		this->troops = troops;
	}

	//void Territory::setOwner(Player* owner) {
	//	this->owner = owner;
	//}
};

// Defines a continent containing several territories on a map
class Continent {
private:
	std::string name;
	int value;
	Territory *territories [];

public:
	// Constructor
	Continent(std::string name, int value, Territory *territories[]) {
		this->name = name;
		this->value = value;
		// TODO: copy territory array to continent
	}

	// Accessors
	int Continent::getValue() {
		return this->value;
	}

	std::string Continent::getName() {
		return this->name;
	}

	bool Continent::isUnited() {
		// TODO: determine whether a continent is united
	}
};

// Defines the entirety of the map
class Map {
	Continent *continents []; // TODO: figure out why this is deemed an "incomplete type"
	Territory *territories [];
};

// Defines a Binary Matrix with which connectivity and adjacency of Territories can be determined
class BinaryMatrix {
	// TODO: create the BinaryMatrix class
};