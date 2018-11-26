//
// Created by Michael Wu on 2018-10-03.
//

#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck(std::vector<std::string> &territory_list)
{
    unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count(); // seed for shuffling
    default_random_engine generator(seed);
    this->current_set = 0;
    //TODO: validate data by throwing exception??

    shuffle(territory_list.begin(), territory_list.end(), generator);

    int num_type = (int)floor(territory_list.size() / 3);
    int remainder = (int)territory_list.size() - (num_type * 3);

    for (unsigned int i = 0; i < (territory_list.size() - remainder); i+=3) {
        this->cards.emplace_back(Card(0, territory_list[i]));
        this->cards.emplace_back(Card(1, territory_list[i + 1]));
        this->cards.emplace_back(Card(2, territory_list[i + 2]));
    }

    if (remainder > 0) {
        std::uniform_int_distribution<> dis(0, 2);
        for (unsigned int i = 1; i <= remainder; i++) {
            this->cards.emplace_back(dis(generator), territory_list[territory_list.size() - i]);
        }
    }

	for (int i = 0; i < this->cards.size(); i++) {
		cards[i].set_deck(this);
	}

    //TODO: do something with the remainder, maybe implement wild cards ??
    shuffle(this->cards.begin(), this->cards.end(), generator);
}

Card& Deck::draw()
{
    if (this->cards.empty()) {
        cout << "Deck is empty." << endl;
    }

    Card* card = &this->cards.back();
    this->cards.pop_back();
    return *card;
}

void Deck::increment_set()
{
    this->current_set++;
}

int Deck::get_current_set()
{
    return this->current_set;
}

void Deck::display_deck()
{
    std::cout << "Deck: " << std::endl;
    for (Card &card : this->cards) {
        card.display_card();
    }
    std::cout << "\n";
}

void Deck::place_back_cards(Card card1, Card card2, Card card3)
{
    this->cards.emplace_back(card1);
    this->cards.emplace_back(card2);
    this->cards.emplace_back(card3);

    unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count(); // seed for shuffling
    default_random_engine generator(seed);

    shuffle(this->cards.begin(), this->cards.end(), generator);
}

int Deck::get_size() {
    return this->cards.size();
}