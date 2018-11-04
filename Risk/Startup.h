//
// Created by Michael Wu on 2018-10-28.
//

#ifndef RISK_STARTUP_H
#define RISK_STARTUP_H

#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <string>
#include <iostream>

#include "map/Map.h"
#include "player/Player.h"

using namespace std;

class Startup {
private:
    Startup() { }; // Disallow creation of a Startup instance

public:
    static void generate_order_of_play(vector<Player*> &players, default_random_engine &generator); // determines the order of play
    static void assign_countries(vector<Player*> &players, vector<Territory*> &territories, default_random_engine &generator); // randomly assigns all country to each players
    static void assign_armies(vector<Player*> &players); // assigns the number of armies depending on the number of players
    static void execute_startup_phase(vector<Player*> &players, vector<Territory*> &territories); // initiate the startup phase
};

#endif //RISK_STARTUP_H
