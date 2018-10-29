//
// Created by Michael Wu on 2018-10-03.
//

#ifndef RISK_DECK_CARD_H
#define RISK_DECK_CARD_H

#include <string>

class Card {
private:
    static std::string types[];
    int card_type;
    std::string territory;

public:
    Card(int cardType, const std::string &territory_str);
    int get_value();
    std::string get_type();
    std::string get_territory();
    void display_card();
};

#endif //RISK_DECK_CARD_H