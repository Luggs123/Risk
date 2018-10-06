//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_CARD_H
#define RISK_DECK_CARD_H

#include <string>
#include "CardType.h"

class Card {
private:
    CardType type;
    std::string territory;

public:
    Card(CardType cardType, const std::string &territoryStr);
    CardType getType();
    std::string getTerritory();
    void displayCard();
};

#endif //RISK_DECK_CARD_H