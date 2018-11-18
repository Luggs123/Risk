//
// Created by Michael Wu on 2018-11-03.
//

#include "Game.h"

/**
 * Initiate the main game loop, in a round robin fashion, where each player can reinforce, attack and fortify.
 * @param players
 * @param territories
 * @param isTest
 */
void Game::execute_main_game_loop(vector<Player*> &players, vector<Territory*> &territories)
{
    bool game_continue = true;
    string winner_id;

    do {
        for (auto &player : players) {
            string player_id = player->getPID();

            if (player->get_own_territories().size() == territories.size()) {
                winner_id = player_id;
                game_continue = false;
                break;
            }

            player->reinforce();

            player->attack();

            player->fortify();

            cout << "\n";
        }
    } while (game_continue);

    cout << "Player " << winner_id << " won!" << endl;
}