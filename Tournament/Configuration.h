//
// Created by Michael Wu on 2018-11-29.
//

#ifndef RISK_CONFIGURATION_H
#define RISK_CONFIGURATION_H

#include <vector>
#include <string>
#include "Player.h"

class Configuration {
private:
    std::vector<std::string*>* maps_list;
    std::vector<string*>* players_list;
    int num_of_games;
    int num_of_turns;

public:
    Configuration(std::vector<std::string*>* maps, std::vector<string*>* players, int games, int turns) : maps_list(maps), players_list(players), num_of_games(games), num_of_turns(turns) { };
    ~Configuration();
    std::vector<std::string*>* get_maps();
    std::vector<string*>* get_players();
    int get_num_of_maps();
    int get_num_of_players();
    int get_num_of_games();
    int get_num_of_turns();
};


#endif //RISK_CONFIGURATION_H
