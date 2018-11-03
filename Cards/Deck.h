//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_DECK_H
#define RISK_DECK_DECK_H

#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
    int currentSet;

public:
	Deck();
    Deck(std::vector<std::string> &territoryList);
    Card draw();
    void incrementSet();
    int getCurrentSet();
    void displayDeck();
    void placeBackCards(Card card1, Card card2, Card card3);
};

#endif //RISK_DECK_DECK_H