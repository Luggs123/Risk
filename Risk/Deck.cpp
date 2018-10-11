//
// Created by Michael Wu on 2018-10-03.
//

#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include "Deck.h"
#include "Card.h"

Deck::Deck(std::vector<std::string> &territoryList)
{
    using namespace std;

    unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count(); // seed for shuffling
    default_random_engine generator(seed);
    this->currentSet = 0;
    //TODO: validate data by throwing exception??

    shuffle(territoryList.begin(), territoryList.end(), generator);

    int numType = (int)floor(territoryList.size() / 3);
    int remainder = (int)territoryList.size() - (numType * 3);

    for (unsigned int i = 0; i < (territoryList.size() - remainder); i+=3) {
        this->cards.emplace_back(Card(0, territoryList[i]));
        this->cards.emplace_back(Card(1, territoryList[i + 1]));
        this->cards.emplace_back(Card(2, territoryList[i + 2]));
    }

    if (remainder > 0) {
        std::uniform_int_distribution<> dis(0, 2);
        for (unsigned int i = 1; i <= remainder; i++) {
            this->cards.emplace_back(dis(generator), territoryList[territoryList.size() - i]);
        }
    }

    //TODO: do something with the remainder, maybe implement wild cards ??
    shuffle(this->cards.begin(), this->cards.end(), generator);
}

Card Deck::draw()
{
    using namespace std;

    if (this->cards.empty()) {
        cout << "Deck is empty." << endl;
    }

    Card card = this->cards.back();
    this->cards.pop_back();
    return card;
}

void Deck::incrementSet()
{
    this->currentSet++;
}

int Deck::getCurrentSet()
{
    return this->currentSet;
}

void Deck::displayDeck()
{
    std::cout << "Deck: " << std::endl;
    for (Card &card : this->cards) {
        card.displayCard();
    }
    std::cout << "\n";
}

void Deck::placeBackCards(Card card1, Card card2, Card card3)
{
    using namespace std;
    this->cards.emplace_back(card1);
    this->cards.emplace_back(card2);
    this->cards.emplace_back(card3);

    unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count(); // seed for shuffling
    default_random_engine generator(seed);

    shuffle(this->cards.begin(), this->cards.end(), generator);
}