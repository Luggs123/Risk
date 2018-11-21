// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "../Map/Map.h"
#include "../Map/MapLoader.h"
#include "../Player/Player.h"
#include "../Dice/Dice.h"
#include "../Deck/Card.h"
#include "../Deck/Deck.h"
#include "../Deck/Hand.h"
#include "../View/View.h"

// A payload of objects to be used by other game phases
class Payload {
private:
    Map* map;
    std::vector<Player*>* players;
    std::vector<View*>* views;
    Deck* deck;

public:
    // Constructor
    Payload(Map* m, std::vector<Player*>* p, Deck* d);

    // Accessors
    Map& get_map();
    std::vector<Player*>& get_players();
    Deck& get_deck();
    std::vector<View*>& get_views();
};

#endif