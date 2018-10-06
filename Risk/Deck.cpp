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
#include "CardType.h"

Deck::Deck(std::vector<std::string> &territoryList)
{
    using namespace std;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); // seed for shuffling
    this->currentSet = 0;
    //TODO: validate data by throwing exception??

    shuffle(territoryList.begin(), territoryList.end(), default_random_engine(seed));

    vector<Card> deckOfCard;
    int numType = (int)floor(territoryList.size() / 3);
    int remainder = (int)territoryList.size() - (numType * 3);

    for (unsigned int i = 0; i < (territoryList.size() - remainder); i+=3) {
        deckOfCard.emplace_back(Card(CardType::ARTILLERY, territoryList.at(i)));
        deckOfCard.emplace_back(Card(CardType::INFANTRY, territoryList.at(i + 1)));
        deckOfCard.emplace_back(Card(CardType::CAVALRY, territoryList.at(i + 2)));
    }

    //TODO: do something with the remainder, maybe implement wild cards ??
    shuffle(deckOfCard.begin(), deckOfCard.end(), default_random_engine(seed));

    for (const auto &i : deckOfCard) {
        this->cards.push(i);
    }
}

Card Deck::draw()
{
    using namespace std;

    if (this->cards.empty()) {
        cout << "Deck is empty." << endl;
    }

    Card card = this->cards.top();
    this->cards.pop();
    return card;
}

void Deck::incrementSet() {
    this->currentSet++;
}

int Deck::getCurrentSet() {
    return this->currentSet;
}

void Deck::displayDeck() {
    std::stack<Card> deckCopy = this->cards;
    std::cout << "Deck: " << std::endl;
    for (int i = 0; i < this->cards.size(); i++) {
        Card card = deckCopy.top();
        card.displayCard();

        deckCopy.pop();
    }
    std::cout << "\n";
}