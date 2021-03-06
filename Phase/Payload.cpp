// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#include "Payload.h"

Payload::Payload(Map* m, std::vector<Player*>* p, Deck* d) : map(m), players(p), deck(d) {}

Map& Payload::get_map() {
    return *this->map;
}

std::vector<Player*>& Payload::get_players() {
    return *this->players;
}

Deck& Payload::get_deck() {
    return *this->deck;
}

std::vector<View*>& Payload::get_views() {
    return *this->views;
}