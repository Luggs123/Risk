//
// Created by Michael Wu on 2018-10-03.
//

#include <iostream>
#include "Card.h"

std::string Card::types[] = {"INFANTRY", "ARTILLERY", "CAVALRY"}; //TODO: global variable bad practice ?!

Card::Card(int val, const std::string &territoryStr) : card_type(val), territory(territoryStr) { }

int Card::get_value() {
    return this->card_type;
}

std::string Card::get_territory()
{
    return this->territory;
}

std::string Card::get_type()
{
    return Card::types[this->card_type];
}

void Card::display_card() {
    std::cout << "Card type: " << this->get_type() << " | Card territory: " << this->get_territory() << std::endl;
}

