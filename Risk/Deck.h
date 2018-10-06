//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_DECK_H
#define RISK_DECK_DECK_H

#include <vector>
#include <string>
#include <stack>
#include "Card.h"

class Deck {
private:
    std::stack<Card> cards;
    int currentSet;

public:
    Deck(std::vector<std::string> &territoryList);
    Card draw();
    void incrementSet();
    int getCurrentSet();
    void displayDeck();

};

#endif //RISK_DECK_DECK_H