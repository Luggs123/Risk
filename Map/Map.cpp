// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include "Map.h"
#include "../Player/Player.h"

// ================== TERRITORY ==================
// Constructor
Territory::Territory(std::string name) {
	this->name = name;
}

// Accessors
int Territory::get_troops() {
	return this->troops;
}

std::string Territory::get_name() {
	return this->name;
}

std::vector<Territory*> Territory::get_neighbors() {
	return this->neighbors;
}

Player* Territory::get_owner() {
	return this->owner;
}

// Mutators
void Territory::set_troops(int troops) {
	this->troops = troops;
}

void Territory::add_neighbor(Territory* t) {
	this->neighbors.push_back(t);
}

void Territory::set_owner(Player* owner) {
	this->owner = owner;
}

// Service Methods
bool Territory::equals(Territory* t) {
	return this->name == t->name;
}

// ================== CONTINENT ==================
// Constructor
Continent::Continent(std::string name, int value, std::vector<Territory*> territories) {
	this->name = name;
	this->value = value;
	this->territories = territories;
}

Continent::Continent(std::string name, int value) {
	this->name = name;
	this->value = value;
}

// Accessors
int Continent::get_value() {
	return this->value;
}

std::string Continent::get_name() {
	return this->name;
}

std::vector<Territory*> Continent::get_territories() {
	return this->territories;
}

// Mutators
void Continent::add_territory(Territory* t) {
	this->territories.push_back(t);
}

// Service Methods
bool Continent::equals(Continent* c) {
	return this->get_name() == c->get_name();
}

bool Continent::is_connected() {
	for (Territory* t : this->get_territories()) {
		bool* visited = new bool[this->get_territories().size()];
		for (int i = 0; i < this->get_territories().size(); i++) {
			visited[i] = false;
		}
		bfs(t, visited);

	// Check if all nodes were visited.
		for (int i = 0; i < territories.size(); i++) {
			if (!visited[i]) {
				delete[] visited;
				return false;
			}
		}
		delete[] visited;
	}
	return true;
}

void Continent::bfs(Territory* origin, bool* visited) {
	std::queue<Territory*> q;
	q.push(origin);
	while (!q.empty()) {
		Territory* node = q.front();
		q.pop();
		visited[this->index_territory(node)] = true;
		for (int i = 0; i < node->get_neighbors().size(); i++) {
			Territory* connection = node->get_neighbors()[i];
			if (index_territory(connection) != -1 && !visited[this->index_territory(connection)]) {
				q.push(connection);
			}
		}
	}
}

// Gets the index of a territory in the territories vector, -1 if not in this continent
int Continent::index_territory(Territory* t) {
	for (int i = 0; i < this->territories.size(); i++) {
		if (this->territories.at(i)->equals(t)) {
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
Map::Map() {}
Map::Map(std::vector<Continent*> continents, std::vector<Territory*> territories) {
	this->continents = continents;
	this->territories = territories;
}

// Mutators
void Map::add_continent(Continent* c) {
	for (Continent* cnt : this->continents) {
		if (c->equals(cnt)) {
			return;
		}
		this->continents.push_back(c);
	}
}

// Service Methods
// Determines the connectivity of the Map
bool Map::is_connected() {
	for (Territory* t : this->territories) {
		bool* visited = new bool[this->territories.size()];
		for (int i = 0; i < this->territories.size(); i++) {
			visited[i] = false;
		}
		bfs(territories[0], visited);

		// Check if all nodes were visited.
		for (int i = 0; i < territories.size(); i++) {
			if (!visited[i]) {
				delete[] visited;
				return false;
			}
		}
		delete[] visited;
	}
	return true;
}

void Map::bfs(Territory* origin, bool* visited) {
	std::queue<Territory*> q;
	q.push(origin);
	while (!q.empty()) {
		Territory* node = q.front();
		q.pop();
		visited[this->index_territory(node)] = true;
		for (int i = 0; i < node->get_neighbors().size(); i++) {
			Territory* connection = node->get_neighbors()[i];
			if (index_territory(connection) != -1 && !visited[this->index_territory(connection)]) {
				q.push(connection);
			}
		}
	}
}

// Gets the index of a territory in the territories vector, -1 if not placed on the map
int Map::index_territory(Territory* t) {
	for (int i = 0; i < this->territories.size(); i++) {
		if (this->territories.at(i)->equals(t)) {
			return i;
		}
	}
	return -1; 
}

// Determines the validity of the map
bool Map::is_valid() {
	for (Continent* c : this->continents) {
		if (!c->is_connected()) {
			return false;
		}
	}

	return this->is_connected();
}