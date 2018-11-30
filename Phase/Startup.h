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

#include "../Map/Map.h"
#include "../Player/Player.h"

using namespace std;

class Startup {
private:
    Startup() { }; // Disallow creation of a Startup instance
    static void generate_order_of_play(vector<Player*> &players, default_random_engine &generator); // determines the order of play
    static void assign_countries(vector<Player*> &players, vector<Territory*> &territories, default_random_engine &generator); // randomly assigns all country to each players
    static void assign_armies(vector<Player*> &players); // assigns the number of armies depending on the number of players
    static void assign_armies_for_tournament(vector<Player*> &players);

public:
    static void execute_startup_phase(vector<Player*> &players, vector<Territory*> &territories); // initiate the startup phase
    static void execute_startup_phase_for_tournament(vector<Player*> &players, vector<Territory*> &territories);
};

#endif //RISK_STARTUP_H