//
// Created by Michael Wu on 2018-11-03.
//

#ifndef RISK_GAME_H
#define RISK_GAME_H

#include <vector>
#include <iostream>
#include <string>

#include "player/Player.h"

using namespace std;

class Game {
private:
    Game() { } // prevents instantiation of this class

public:
    //TODO: remove isTest parameter, used only for demo (Game_Driver)
    static void execute_main_game_loop(vector<Player*> &players, vector<Territory*> &territories, bool isTest); // initiate the main game loop
};

#endif //RISK_GAME_H
