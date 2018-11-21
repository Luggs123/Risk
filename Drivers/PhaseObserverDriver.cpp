//
// Created by Michael Wu on 2018-11-18.
//

#include "Driver.h"
#include "../Phase/Start.h"
#include "../Phase/Startup.h"
#include "../Phase/Game.h"
#include "../View/View.h"

int driver::phase_observer_driver() {
    Payload* payload = Start::prompt_start();
    Startup::execute_startup_phase(payload->get_players(), payload->get_map().territories);
    Game::execute_main_game_loop(payload->get_players(), payload->get_map().territories);

    return 0;
}