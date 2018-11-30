//
// Created by Michael Wu on 2018-11-03.
//

#ifndef RISK_GAME_H
#define RISK_GAME_H

#include <vector>
#include <iostream>
#include <string>

#include "../Player/Player.h"

using namespace std;

class Game {
private:
    Game() { } // prevents instantiation of this class

public:
    static void execute_main_game_loop(vector<Player*> &players, vector<Territory*> &territories); // initiate the main game loop
    static string execute_main_game_loop_for_tournament(vector<Player*> &players, vector<Territory*> &territories, int turns_limit);
};

#endif //RISK_GAME_H