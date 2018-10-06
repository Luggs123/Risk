#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"

int main()
{
    using namespace std;
    vector<string> territoryList;
    territoryList.emplace_back("Canada");
    territoryList.emplace_back("Usa");
    territoryList.emplace_back("Mexico");

    Deck deck(territoryList);
    deck.displayDeck();

    Hand myHand;
    myHand.displayCards();

    Card card1 = deck.draw();
    myHand.placeCardInHand(card1);

    myHand.displayCards();
    deck.displayDeck();
}