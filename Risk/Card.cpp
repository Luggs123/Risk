//
// Created by Michael Wu on 2018-10-03.
//

#include <iostream>
#include "Card.h"

std::string Card::types[] = {"INFANTRY", "ARTILLERY", "CAVALRY"}; //TODO: global variable bad practice ?!

Card::Card(int val, const std::string &territoryStr) : cardType(val), territory(territoryStr) { }

int Card::getValue() {
    return this->cardType;
}

std::string Card::getTerritory()
{
    return this->territory;
}

std::string Card::getType()
{
    return Card::types[this->cardType];
}

void Card::displayCard() {
    std::cout << "Card type: " << this->getType() << " | Card territory: " << this->getTerritory() << std::endl;
}

