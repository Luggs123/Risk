//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_DECK_H
#define RISK_DECK_DECK_H

#include <vector>
#include <string>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
    int current_set;

public:
    Deck(std::vector<std::string> &territory_list);
    Card draw();
    void increment_set();
    int get_current_set();
    void display_deck();
    void place_back_cards(Card card1, Card card2, Card card3);
};

#endif //RISK_DECK_DECK_H