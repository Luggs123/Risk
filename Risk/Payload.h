// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "../Map/Map.h"
#include "../Map/MapLoader.h"
#include "../Player/Player.h"
#include "../Dice/dice.h"
#include "../Cards/Card.h"
#include "../Cards/Deck.h"
#include "../Cards/Hand.h"

// A payload of objects to be used by other game phases
class Payload {
private:
	Map map;
	std::vector<Player*> players;
	Deck deck;

public:
	// Constructor
	Payload();
	Payload(Map m, std::vector<Player*> p, Deck d);

	// Accessors
	Map get_map();
	std::vector<Player*> get_players();
	Deck get_deck();
};

#endif