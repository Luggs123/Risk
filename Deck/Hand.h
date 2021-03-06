//
// Created by Michael Wu on 2018-10-04.
//

#ifndef RISK_DECK_HAND_H
#define RISK_DECK_HAND_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Deck.h"

namespace hand_helper_function
{
    bool is_exchange_valid(Card &card1, Card &card2, Card &card3);
}

class Hand {
private:
    std::vector<Card> hand;
	Deck* deck;

public:
    //TODO: armies are represented as int ??
    int exchange(unsigned int pos1, unsigned int pos2, unsigned int pos3, Deck &current_deck);
	int exchange(unsigned int pos1, unsigned int pos2, unsigned int pos3);
    void display_cards();
    void place_card_in_hand(Card &card);

	int reinforcementcheck();
	void add_card_on_hand();
	void set_deck(Deck* D);
};

#endif //RISK_DECK_HAND_H