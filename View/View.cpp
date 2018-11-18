//
// Created by Michael Wu on 2018-11-17.
//

#include "View.h"
#include "../Player/Player.h"

using namespace std;

View::View(Player *player) {
    this->current_player = player;
}

void View::display_phase(GamePhase current_phase) {
    string phase;
    switch (current_phase) {
        case GamePhase::ATTACK:
            phase = "ATTACK PHASE";
            break;
        case GamePhase::REINFORCEMENT:
            phase = "REINFORCEMENT PHASE";
            break;
        case GamePhase::FORTIFY:
            phase = "FORTIFY PHASE";
            break;
        default:
            phase = "UNDEFINED PHASE";
    }

    cout << "********** " << this->current_player->getPID() << " : " << phase << " **********" << endl;
}

void View::display_info(GamePhase current_phase) {
    //TODO: show relevant information depending on the phase
    switch (current_phase) {
        case GamePhase::ATTACK:
            cout << "attack info" << endl;
            break;
        case GamePhase::REINFORCEMENT:
            cout << "reinforcement info" << endl;
            break;
        case GamePhase::FORTIFY:
            cout << "fortify info" << endl;
            break;
        default:
            cout << "UNDEFINED PHASE" << endl;
    }
}

void View::update(GamePhase data) {
    display_phase(data);
    display_info(data);
}