//
// Created by Michael Wu on 2018-11-13.
//

#ifndef RISK_DRIVER_H
#define RISK_DRIVER_H

namespace driver {
    int dice_driver();
    int map_driver();
    int map_loader_driver();
    int player_driver();
    int deck_driver();
    int game_start_driver();
    int startup_driver();
    int main_game_driver();
    int attack_driver();
    int reinforcement_driver();
    int fortification_driver();
    int benevolent_strategy_driver();
	int aggressive_strategy_driver();
	int human_strategy_driver();
	int phase_observer_driver();
	int game_statics_observer_driver();
	int tournament_driver();
}

#endif //RISK_DRIVER_H
