#include "../Deck/Deck.h"
#include "../Deck/Hand.h"
#include "../Deck/Card.h"
#include "Driver.h"

namespace test {
    std::vector<std::string> generate_territory_vector();

};

int driver::deck_driver()
{
    using namespace std;

    // army variable should be in player but for this demo, it'll be stored in the driver
    int army_num = 0;

    vector<string> territory_list = test::generate_territory_vector();

    Deck deck(territory_list);
    Hand my_hand;

    cout << "Initial deck content." << endl;
    deck.display_deck();

    cout << "Initial hand content." << endl;
    my_hand.display_cards();

    cout << "Initial army count: " << army_num << endl;
    cout << "\n";

    Card card1 = deck.draw();
    cout << "Draw a card." << endl;
    card1.display_card();
    cout << "\n";

    cout << "Place card in hand." << endl;
    my_hand.place_card_in_hand(card1);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.display_deck();

    cout << "Hand content." << endl;
    my_hand.display_cards();

    cout << "Attempting to exchange cards in hand." << endl;
    army_num += my_hand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << army_num << endl;
    cout << "\n";

    Card card2 = deck.draw();
    cout << "Draw a card." << endl;
    card2.display_card();
    cout << "\n";

    cout << "Place card in hand." << endl;
    my_hand.place_card_in_hand(card2);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.display_deck();

    cout << "Hand content." << endl;
    my_hand.display_cards();

    cout << "Attempting to exchange cards in hand." << endl;
    army_num += my_hand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << army_num << endl;
    cout << "\n";

    Card card3 = deck.draw();
    cout << "Draw a card." << endl;
    card3.display_card();
    cout << "\n";

    cout << "Place card in hand." << endl;
    my_hand.place_card_in_hand(card3);
    cout << "\n";

    cout << "Deck content." << endl;
    deck.display_deck();

    cout << "Hand content." << endl;
    my_hand.display_cards();

    cout << "Attempting to exchange cards in hand." << endl;
    army_num += my_hand.exchange(0, 1, 2, deck);

    cout << "Current army count: " << army_num << endl;
    cout << "\n";

    cout << "Deck content." << endl;
    deck.display_deck();

    cout << "Hand content." << endl;
    my_hand.display_cards();

	system("PAUSE");
	return 0;
}

namespace test {
    using namespace std;

    vector<string> generate_territory_vector()
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