//
// Created by Michael Wu on 2018-11-29.
//

#ifndef RISK_TOURNAMENT_H
#define RISK_TOURNAMENT_H

#include <vector>
#include <string>
#include "Configuration.h"
#include "../Player/Player.h"

class Tournament {
private:
    Tournament() { } // prevent instantiation of this class

    // helper functions
    static Configuration* configure_tournament();
    static std::vector<std::string*>* prompt_map_selection();
    static int prompt_players();
    static int prompt_games();
    static int prompt_turns();
    static std::vector<string*>* prompt_computer_players();
    static void execute_tournament(Configuration* config);

public:
    static void begin_tournament();
};


#endif //RISK_TOURNAMENT_H
