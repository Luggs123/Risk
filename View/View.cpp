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

void View::display_info(GamePhase current_phase, vector<string>* event_data) {
    //TODO: show relevant information depending on the phase
    vector<string> data = *event_data;
    switch (current_phase) {
        case GamePhase::ATTACK:
            cout << "Player " << current_player->getPID() << " attacked " << data[0] << " from " << data[1] << endl;
            break;
        case GamePhase::REINFORCEMENT:
            cout << "Player " << current_player->getPID() << " reinforced " << data[0] << " with " << data[1] << " troops." << endl;
            break;
        case GamePhase::FORTIFY:
            cout << "Player " << current_player->getPID() << " fortified " << data[0] << " with " << data[1] << " troops." << endl;
            break;
        default:
            cout << "UNDEFINED PHASE" << endl;
    }
}

void View::update(GamePhase data, vector<string>* event_data = nullptr) {
    cout << endl;
    if (event_data == nullptr) {
        display_phase(data);
    } else {
        display_info(data, event_data);
    }
    cout << endl;
}