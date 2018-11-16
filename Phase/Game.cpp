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
void Game::execute_main_game_loop(vector<Player*> &players, vector<Territory*> &territories, bool isTest = false)
{
    bool game_continue = true;
    string winner_id = "";

    do {
        for (auto &player : players) {
            string player_id = player->getPID();

            if (player->get_own_territories().size() == territories.size()) {
                winner_id = player_id;
                game_continue = false;
                break;
            }

            cout << "Player " << player->getPID() << " turn" << endl;

            cout << "Reinforcement phase" << endl;
            //TODO: call reinforcment phase

            cout << "Attack phase" << endl;
            //TODO: call attack phase

            cout << "Fortification phase" << endl;
            //TODO: call fortification phase

            cout << "\n";
        }

        //remove this if block, only used for demo purposes
        if (isTest) {
            string user_input;
            getline(cin, user_input);

            if (user_input == "end") {
                for (int i = 0; i < players.size(); i++) {
                    players[i]->get_own_territories().clear();

                    if (i == 0) {
                        for (auto &territory : territories) {
                            players[i]->add_territory(territory);
                        }
                    }
                }
            }
        }
    } while (game_continue);

    cout << "Player " << winner_id << " won!" << endl;
}