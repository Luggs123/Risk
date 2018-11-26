//
// Created by Michael Wu on 2018-10-03.
//

#include "Card.h"

std::string Card::types[] = {"INFANTRY", "ARTILLERY", "CAVALRY"};

Card::Card(int val, const std::string &territoryStr) : card_type(val), territory(territoryStr) { }

int Card::get_value() {
    return this->card_type;
}

std::string& Card::get_territory()
{
    return this->territory;
}

std::string& Card::get_type()
{
    return Card::types[this->card_type];
}

void Card::display_card() {
    std::cout << "Card type: " << this->get_type() << " | Card territory: " << this->get_territory() << std::endl;
}

void Card::set_deck(Deck* D) {
	this->belongs = D;
}

Deck* Card::get_deck() {
	return this->belongs;
}

