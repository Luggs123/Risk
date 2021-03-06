//
// Created by Michael Wu on 2018-11-17.
//

#ifndef RISK_VIEW_H
#define RISK_VIEW_H

#include <iostream>

#include "../Phase/GamePhase.h"
#include "../ObserverPattern/Observer.h"

class Player;

class View : public Observer {
private:
    Player* current_player;
    void display_phase(GamePhase current_phase);
    void display_info(GamePhase current_phase, std::vector<std::string>* event_data);

public:
    View(Player* player);
    void update(GamePhase data, std::vector<std::string>* event_data);
};


#endif //RISK_VIEW_H
