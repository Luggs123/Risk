
#include "Hand.h"

namespace test {
    std::vector<std::string> generateTerritoryVector();

};

int main()
{
    using namespace std;

    // army variable should be in player but for this demo, it'll be stored in the driver
    int armyNum = 0;

    vector<string> territoryList = test::generateTerritoryVector();

    Deck deck(territoryList);
    Hand myHand;

    cout << "Initial deck content." << endl;
    deck.displayDeck();

    cout << "Initial hand content." << endl;
    myHand.displayCards();

    cout << "Initial army count: " << armyNum << endl;
    cout << "\n";

    Card card1 = deck.draw();
    cout << "Draw a card." << endl;
    card1.displayCard();
    cout << "\n";

    cout << "Place card in hand." << endl;
    myHand.placeCardInHand(card1);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.displayDeck();

    cout << "Hand content." << endl;
    myHand.displayCards();

    cout << "Attempting to exchange cards in hand." << endl;
    armyNum += myHand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << armyNum << endl;
    cout << "\n";

    Card card2 = deck.draw();
    cout << "Draw a card." << endl;
    card2.displayCard();
    cout << "\n";

    cout << "Place card in hand." << endl;
    myHand.placeCardInHand(card2);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.displayDeck();

    cout << "Hand content." << endl;
    myHand.displayCards();

    cout << "Attempting to exchange cards in hand." << endl;
    armyNum += myHand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << armyNum << endl;
    cout << "\n";

    Card card3 = deck.draw();
    cout << "Draw a card." << endl;
    card3.displayCard();
    cout << "\n";

    cout << "Place card in hand." << endl;
    myHand.placeCardInHand(card3);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.displayDeck();

    cout << "Hand content." << endl;
    myHand.displayCards();

    cout << "Attempting to exchange cards in hand." << endl;
    armyNum += myHand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << armyNum << endl;
    cout << "\n";

    cout << "Deck content." << endl;
    deck.displayDeck();

    cout << "Hand content." << endl;
    myHand.displayCards();

	system("PAUSE");
}

namespace test {
    using namespace std;

    vector<string> generateTerritoryVector()
    {
        vector<string> territories;

        territories.emplace_back("Canada");
        territories.emplace_back("Usa");
        territories.emplace_back("Mexico");
        territories.emplace_back("Russia");
        territories.emplace_back("France");
        territories.emplace_back("United-Kingdom");
        territories.emplace_back("China");
        territories.emplace_back("Spain");
        territories.emplace_back("Italy");
        territories.emplace_back("Japan");
        territories.emplace_back("Egypt");

        return territories;
    };
}