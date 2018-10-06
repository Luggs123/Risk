//
// Created by Michael Wu on 2018-10-03.
//

#include <iostream>
#include "Card.h"
#include "CardType.h"

std::string Card::getTerritory()
{
    return this->territory;
}

CardType Card::getType()
{
    return this->type;
}

Card::Card(CardType cardType, const std::string &territoryStr)
{
    this->type = cardType;
    this->territory = territoryStr;
}

void Card::displayCard() {
    std::cout << "Card type: " << this->getType() << " | Card territory: " << this->getTerritory() << std::endl;
}

