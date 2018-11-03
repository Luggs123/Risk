//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_CARD_H
#define RISK_DECK_CARD_H

#include <string>
#include <iostream>

class Card {
private:
    static std::string types[];
    int cardType;
    std::string territory;

public:
    Card(int cardType, const std::string &territoryStr);
    int getValue();
    std::string getType();
    std::string getTerritory();
    void displayCard();
};

#endif //RISK_DECK_CARD_H