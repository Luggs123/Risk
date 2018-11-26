//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_CARD_H
#define RISK_DECK_CARD_H

#include <string>
#include <iostream>

class Deck;

class Card {
private:
    static std::string types[];
    int card_type;
    std::string territory;
	Deck* belongs;

public:
    Card(int cardType, const std::string &territory_str);
    int get_value();
    std::string& get_type();
    std::string& get_territory();
    void display_card();
	void set_deck(Deck * D);
	Deck* get_deck();
};

#endif //RISK_DECK_CARD_H