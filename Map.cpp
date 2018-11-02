// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#include "Attack.h"

// ================== TERRITORY ==================
// Constructor
Territory::Territory(std::string name) {
	this->name = name;
}
Territory::Territory(string na, int trp, Player* owner) {
	name = na;
	troops = trp;
	this->setOwner(owner);

}

// Accessors
int Territory::getTroops() {
	return troops;
}

std::string Territory::getName() {
	return this->name;
}

std::vector<Territory*> Territory::getNeighbors() {
	return this->neighbors;
}

Player* Territory::getOwner() {
 return this->owner;
}

// Mutators
void Territory::setTroops(int troops) {
	this->troops = troops;
}

void Territory::addNeighbor(Territory* t) {
	this->neighbors.push_back(t);
}

void Territory::setOwner(Player* owner) {
	this->owner = owner;
}



