//
// Created by Michael Wu on 2018-10-04.
//

#include <functional>
#include "Hand.h"
#include "Card.h"
#include "Deck.h"

int Hand::exchange(unsigned int pos1, unsigned int pos2, unsigned int pos3, Deck &current_deck)
{
    using namespace std;
    using namespace hand_helper_function;

    if (this->hand.size() < 3) {
        cout << "You do not have enough cards to trade in." << endl;
        return 0;
    }

    if (pos1 >= hand.size() || pos2 >= hand.size() || pos3 >= hand.size() || pos1 == pos2 || pos1 == pos3 || pos2 == pos3) {
        cout << "Invalid index." << endl;
        return 0;
    }

    Card card1 = this->hand[pos1];
    Card card2 = this->hand[pos2];
    Card card3 = this->hand[pos3];

    unsigned int positions[] = {pos1, pos2, pos3};
    sort(begin(positions), end(positions), greater<>());

    if (is_exchange_valid(card1, card2, card3)) {
        current_deck.increment_set();

        this->hand.erase(this->hand.begin() + positions[0]);
        this->hand.erase(this->hand.begin() + positions[1]);
        this->hand.erase(this->hand.begin() + positions[2]);
        current_deck.place_back_cards(card1, card2, card3);

        return current_deck.get_current_set() * 5;
    }

    return 0;
}


int Hand::exchange(unsigned int pos1, unsigned int pos2, unsigned int pos3)
{
	using namespace std;
	using namespace hand_helper_function;

	if (pos1 >= hand.size() || pos2 >= hand.size() || pos3 >= hand.size() || pos1 == pos2 || pos1 == pos3 || pos2 == pos3) {
		cout << "Invalid index." << endl;
		return 0;
	}

	Card card1 = this->hand[pos1];
	Card card2 = this->hand[pos2];
	Card card3 = this->hand[pos3];

	unsigned int positions[] = { pos1, pos2, pos3 };
	sort(begin(positions), end(positions), greater<>());

	if (is_exchange_valid(card1, card2, card3)) {
		deck->increment_set();

		this->hand.erase(this->hand.begin() + positions[0]);
		this->hand.erase(this->hand.begin() + positions[1]);
		this->hand.erase(this->hand.begin() + positions[2]);
		deck->place_back_cards(card1, card2, card3);

		return deck->get_current_set() * 5;
	}

	return 0;
}


void Hand::display_cards() {
    if (this->hand.empty()) {
        std::cout << "Hand is empty." << std::endl;
    } else {
        std::cout << "Hand: " << std::endl;
        for (Card &card : this->hand) {
            card.display_card();
        }
    }
    std::cout << "\n";
}

void Hand::place_card_in_hand(Card &card) {
    this->hand.push_back(card);
}

namespace hand_helper_function
{
    bool is_exchange_valid(Card &card1, Card &card2, Card &card3)
    {
        if (card1.get_value() == card2.get_value() && card2.get_value() == card3.get_value())
            return true;

        return card1.get_value() != card2.get_value() && card2.get_value() != card3.get_value() && card1.get_value() !=
                                                                                                       card3.get_value();

    }
}

int Hand::reinforcementcheck() {
	int num = 0;
	switch (this->hand.size()) {
	case 0:
		return 0;
		break;
	case 1:
	case 2:
		return 0;
		break;
	default:
		for (int i = 0; i < (this->hand.size() - 2); i++) {
			for (int j = 1; j < (this->hand.size() - 1); j++) {
				for (int k = 2; k < this->hand.size(); k++) {
					num = this->exchange(i, j, k);
					if (num != 0)
						return num;
				}
			}
		}
	}



	return num;
}

void Hand::set_deck(Deck* D) {
	this->deck = D;
}

void Hand::add_card_on_hand() {
	this->place_card_in_hand(this->deck->draw());
}