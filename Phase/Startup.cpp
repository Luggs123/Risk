//
// Created by Michael Wu on 2018-10-28.
//

#include "Startup.h"

/**
 * Determines the order of play
 * @param players
 * @param generator
 */
void Startup::generate_order_of_play(vector<Player*> &players, default_random_engine &generator)
{
    shuffle(players.begin(), players.end(), generator);
}

/**
 * Randomly assigns all territories to each and every player
 * @param players
 * @param territories
 * @param generator
 */
void Startup::assign_countries(vector<Player*> &players, vector<Territory*> &territories, default_random_engine &generator)
{
    int index = 0;
    shuffle(territories.begin(), territories.end(), generator);
    for (auto &territory : territories) {
        if (index == players.size())
            index = 0;

        players[index]->addTerritory(*territory);
        index++;
    }
}

/**
 * Assigns the number of armies depending on the number of players and places them on the player's owned territories.
 * @param players
 */
void Startup::assign_armies(vector<Player*> &players)
{
    int armies = 0;
    switch (players.size()) {
        case 2:
            armies = 40;
            break;
        case 3:
            armies = 35;
            break;
        case 4:
            armies = 30;
            break;
        case 5:
            armies = 25;
            break;
        case 6:
            armies = 20;
            break;
        default:
            cout << "Invalid number of players." << endl;
    }

    for (auto &player : players) {
        player->setFree_Troops(armies);
    }

    for (int i = 0; i < armies; i++) {
        for (auto &player : players) {
            cout << "Player " << player->getPID() << " has " << player->getFree_troops() << " armies left." << endl;
            cout << "Please enter the choose a territory from the following list you will like to place an army in: " << endl;

            int territory_count = static_cast<int>(player->get_own_territories().size());
            for (int j = 0; j < territory_count; j++) {
                Territory* current_territory = player->get_own_territories()[j];
                cout << j << ") " << current_territory->get_name() << " (" << current_territory->get_troops()<< " armies)"<< endl;
            }

            bool invalidInput = true;
            int territory_num;
            do {
                string territory_input;
                getline(cin, territory_input);

                try {
                    territory_num = stoi(territory_input);
                } catch (const exception& e) {
                    territory_num = -1;
                }

                if (territory_num >= 0 && territory_num < player->get_own_territories().size())
                    invalidInput = false;
                else
                    cout << "Invalid territory number. Please try again" << endl;
            } while (invalidInput);

            player->add_troops(territory_num, 1);
        }
    }
}

/**
 * Initiate the startup phase of the game
 * @param players
 * @param territories
 */
void Startup::execute_startup_phase(vector<Player*> &players, vector<Territory*> &territories)
{
    unsigned int seed = (unsigned int)chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    Startup::generate_order_of_play(players, generator);
    Startup::assign_countries(players, territories, generator);
    Startup::assign_armies(players);
}