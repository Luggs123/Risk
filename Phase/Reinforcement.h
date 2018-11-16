#pragma once

#include "../Map/Map.h"
#include "../Deck/Hand.h"

class Player;

class Reinforcement {
private:
    Player * ptemp;
    int num_troop;
    Territory * controlled;
    int num_controlled;

    void check_continent(Map &ma);
    void cal_num_troop();
    void check_hand();
    void get_info();
    void add_troops(Territory* t);
    void reinforce();

public:
    Reinforcement();
    Reinforcement(Player &p);
    void run_reinforcement(Map &ma);
    void run_reinforcement();
};