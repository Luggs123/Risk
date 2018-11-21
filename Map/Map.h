// Assignment 1, Part 1: Map
// Written by Michael Luger, 40055539

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>

class Player;

// Defines an individual territory on the map
class Territory {
private:
	Player* owner;
	std::string name;
	int troops;
	std::vector<Territory*> neighbors;

public:
	// Constructors
	Territory();
	Territory(std::string name);
	Territory(std::string na, int trp, Player* owner);

	// Accessors
	int get_troops();
	std::string get_name();
	std::vector<Territory*> get_neighbors();
	Player* get_owner();

	// Mutators
	void set_troops(int troops);
	void add_neighbor(Territory* t);
	void set_owner(Player* owner);

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
	int get_value();
	std::string get_name();
	std::vector<Territory*> get_territories();

	// Mutators
	void add_territory(Territory* t);

	// Service Methods
	bool equals(Continent* c);
	bool is_connected();
	void bfs(Territory* origin, bool* visited);
	int index_territory(Territory* t);
};

// Defines the entirety of the map
class Map {
public:
	std::vector<Continent*> continents;
	std::vector<Territory*> territories;

	// Constructor
	Map();
	Map(std::vector<Continent*> continents, std::vector<Territory*> territories);

	// Mutators
	void add_continent(Continent* c);

	// Service Methods
	bool is_connected();
	void bfs(Territory* origin, bool* visited);
	int index_territory(Territory* t);
	bool is_valid();
};

#endif