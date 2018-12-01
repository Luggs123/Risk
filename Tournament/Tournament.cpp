//
// Created by Michael Wu on 2018-11-29.
//

#include <iostream>
#include <iomanip>

#include "Tournament.h"
#include "../Phase/Payload.h"
#include "../Phase/Start.h"
#include "../Phase/Startup.h"
#include "../Phase/Game.h"
#include "dirent.h"

using namespace std;

Configuration* Tournament::configure_tournament() {
    vector<string*>* maps = prompt_map_selection();
    vector<string*>* players = prompt_computer_players();
    int num_games = prompt_games();
    int num_turns = prompt_turns();

    return new Configuration(maps, players, num_games, num_turns);
}

vector<string*>* Tournament::prompt_map_selection() {
    int num_of_maps = 0;
    bool invalid_maps = true;

    do {
        cout << "Please enter the number of maps you want to play (1 - 5)." << endl;

        string user_input;
        getline(cin, user_input);

        try {
            num_of_maps = stoi(user_input);

            if (num_of_maps <= 0 || num_of_maps > 5)
                cout << "The number of maps must be between 1 and 5. Please try again." << endl;
            else
                invalid_maps = false;
        } catch (...) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (invalid_maps);

    vector<string*>* maps = new vector<string*>();
    DIR* dir = opendir("../MapTemplates/");
    struct dirent* entry = nullptr;

    if (dir != nullptr) {
        string path;
        vector<string> file_names;

        // fetching the list of maps
        entry = readdir(dir);
        while(entry != nullptr) {
            file_names.emplace_back(entry->d_name);
            entry = readdir(dir);
        }
        closedir(dir);

        // removing entries . and ..
        file_names.erase(file_names.begin());
        file_names.erase(file_names.begin());

        for (int i = 0; i < num_of_maps; i++) {
            // asking the user to choose a map
            int map_id = -1;
            bool invalid_map = true;

            do {
                cout << "Please choose one of the following maps for Map " << i  << ":" << endl;
                for (int j = 0; j < file_names.size(); j++) {
                    cout << j << ") " << file_names[j] << endl;
                }

                string user_input;
                getline(cin, user_input);

                try {
                    map_id = stoi(user_input);
                    if (map_id < 0 || map_id >= file_names.size())
                        cout << "Invalid map. Please try again." << endl;
                    else
                        invalid_map = false;
                } catch (...) {
                    cout << "Invalid input. Please try again." << endl;
                }
            } while (invalid_map);

            maps->push_back(new string(file_names[map_id]));
        }
    } else {
        throw runtime_error("Error opening maps directory.\n");
    }

    return maps;
}

int Tournament::prompt_players() {
    int num_of_players = 0;
    bool invalid_players = true;

    do {
        cout << "Please enter the number of players (2 - 4):" << endl;

        string user_input;
        getline(cin, user_input);

        try {
            num_of_players = stoi(user_input);
            if (num_of_players < 2 || num_of_players > 4)
                cout << "The number of players must be between 2 and 4. Please try again." << endl;
            else
                invalid_players = false;
        } catch (...) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (invalid_players);

    return num_of_players;
}

int Tournament::prompt_games() {
    int num_of_games = 0;
    bool invalid_games = true;

    do {
        cout << "Please enter the number of games (1 - 5):" << endl;

        string user_input;
        getline(cin, user_input);

        try {
            num_of_games = stoi(user_input);
            if (num_of_games < 1 || num_of_games > 5)
                cout << "The number of games must be between 1 and 5. Please try again." << endl;
            else
                invalid_games = false;
        } catch (...) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (invalid_games);

    return num_of_games;
}

int Tournament::prompt_turns() {
    int num_of_turns = 0;
    bool invalid_turns = true;

    do {
        cout << "Please enter the number of turns (10 - 50):" << endl;

        string user_input;
        getline(cin, user_input);

        try {
            num_of_turns = stoi(user_input);
            if (num_of_turns < 10 || num_of_turns > 50)
                cout << "The number of turns must be between 10 and 50. Please try again." << endl;
            else
                invalid_turns = false;
        } catch (...) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (invalid_turns);

    return num_of_turns;
}

vector<string*>* Tournament::prompt_computer_players() {
    int players_count = prompt_players();

    vector<string> computer_players = {"Aggressive", "Benevolent", "Random", "Cheater"};

    vector<string*>* player_vector = new vector<string*>();
    for (int i = 1; i <= players_count; i++) {
        bool invalid_data = true;
        do {
            string user_choice;
            cout << "Please choose a computer behavior for player " << i << endl;

            for (int j = 0; j < computer_players.size(); j++) {
                cout << j << ") " << computer_players[j] << endl;
            }
            getline(cin, user_choice);

            try {
                int choice = stoi(user_choice);
                if (choice < 0 || choice >= computer_players.size()) {
                    cout << "Invalid choice. Please try again." << endl;
                } else {
                    player_vector->push_back(new string(computer_players[choice]));
                    computer_players.erase(computer_players.begin() + choice);
                    invalid_data = false;
                }
            } catch (...) {
                cout << "Invalid input. Please try again." << endl;
            }
        } while (invalid_data);
    }

    return player_vector;
}

void Tournament::execute_tournament(Configuration *config) {
    vector<vector<string>> results;

    for (int i = 0; i < config->get_num_of_maps(); i++) {
        vector<string> current_map_results;

        for (int j = 0; j < config->get_num_of_games(); j++) {
            string path = "../MapTemplates/" + *(config->get_maps()->at(i));
            Payload *payload = Start::start_tournament(path, config->get_players());
            Startup::execute_startup_phase_for_tournament(payload->get_players(), payload->get_map().territories);
            string result = Game::execute_main_game_loop_for_tournament(payload->get_players(),
                                                                        payload->get_map().territories,
                                                                        config->get_num_of_turns());
            current_map_results.push_back(result);
        }

        results.push_back(current_map_results);
    }

    const char delimiter = ' ';

    for (int i = 0; i <= config->get_num_of_games(); i++) {
        if (i == 0) {
            cout << left << setw(20) << setfill(' ') << "Maps";
        } else {
            string col_name = "Game " + to_string(i);
            cout << left << setw(20) << setfill(' ') << col_name;
        }
    }

    cout << endl;

    for (int i = 0; i < config->get_num_of_maps(); i++) {
        cout << left << setw(20) << setfill(delimiter) << *(config->get_maps()->at(i));

        for (int j = 0; j < config->get_num_of_games(); j++) {
            cout << left << setw(20) << setfill(delimiter) << results[i][j];
        }

        cout << endl;
    }
}

void Tournament::begin_tournament() {
    Configuration* tournament_config = configure_tournament();
    execute_tournament(tournament_config);
}