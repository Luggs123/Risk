//
// Created by Michael Wu on 2018-11-29.
//

#include "Configuration.h"

using namespace std;

Configuration::~Configuration() {
    for (string* map : *(maps_list)) {
        delete map;
    }

    maps_list->clear();
    delete maps_list;
}

std::vector<std::string*>* Configuration::get_maps() {
    return maps_list;
}

std::vector<string*>* Configuration::get_players() {
    return players_list;
}

int Configuration::get_num_of_games() {
    return num_of_games;
}

int Configuration::get_num_of_maps() {
    return (int)maps_list->size();
}

int Configuration::get_num_of_players() {
    return (int)players_list->size();
}

int Configuration::get_num_of_turns() {
    return num_of_turns;
}