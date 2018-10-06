//
// Created by Michael Wu on 2018-10-04.
//

#include <iostream>
#include "Hand.h"
#include "Card.h"
#include "Deck.h"

int Hand::exchange(unsigned int pos1, unsigned int pos2, unsigned int pos3, Deck &currentDeck)
{
    using namespace std;
    using namespace hand_helper_function;

    if (this->hand.size() < 3) {
        cout << "You do not have enough cards to trade in." << endl;
        return 0;
    }

    if (pos1 >= hand.size() || pos2 >= hand.size() || pos3 >= hand.size()) {
        cout << "Invalid index." << endl;
        return 0;
    }

    Card card1 = this->hand.at(pos1);
    Card card2 = this->hand.at(pos2);
    Card card3 = this->hand.at(pos3);

    if (isExchangeValid(card1, card2, card3)) {
        currentDeck.incrementSet();

        const int set = currentDeck.getCurrentSet();
        switch (set) {
            case 1:
                return 4;
            case 2:
                return 6;
            case 3:
                return 8;
            case 4:
                return 10;
            case 5:
                return  12;
            case 6:
                return 15;
            default:
                if (set > 6)
                    return 15 + ((set - 6) * 5);

                cout << "Invalid set." << endl;
                return 0;
        }
    }

    return 0;
}

void Hand::displayCards() {
    if (this->hand.empty()) {
        std::cout << "Hand is empty." << std::endl;
    } else {
        std::cout << "Hand: " << std::endl;
        for (Card &card : this->hand) {
            card.displayCard();
        }
    }
    std::cout << "\n";
}

void Hand::placeCardInHand(Card &card) {
    this->hand.push_back(card);
}

namespace hand_helper_function
{
    bool isExchangeValid (Card &card1, Card &card2, Card &card3)
    {
        if (card1.getType() == card2.getType() && card2.getType() == card3.getType())
            return true;

        return card1.getType() != card2.getType() && card2.getType() != card3.getType();

    }
}