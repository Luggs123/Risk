// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#include "Start.h"
#include "../PlayerStrategy/Aggressive.h"
#include "../PlayerStrategy/Random.h"
#include "../PlayerStrategy/Benevolent.h"

using namespace std;

Payload* Start::start(string path, int players) {
    MapLoader ml;
    Map* game_map = ml.get_map(path);
    if (!game_map->is_valid()) {
        //throw "This map is not valid. Retry this program with a valid map file.";
    }

    if (players < 2 || players > 6) {
        //throw "That is not a valid amount of players. Please try again with a different program execution.";
    }

    vector<Player*>* playerVector = new vector<Player*>();
    vector<View*>* views = new vector<View*>();
    for (int i = 1; i <= players; i++) {
        string user_name;
        cout << "Player " << i << ", please enter your name." << endl;
        getline(cin, user_name);

        Player* player = new Player(user_name);
        View* view = new View(player);
        player->attach(view);

        playerVector->push_back(player);
        views->push_back(view);
    }

    vector<string>* territories = new vector<string>();
    for (Territory* t : game_map->territories) {
        territories->push_back(t->get_name());
    }

    Deck* deck = new Deck(*territories);

    return new Payload(game_map, playerVector, deck);
}

Payload* Start::start_tournament(std::string path, vector<string*>* players) {
    MapLoader ml;
    Map* game_map = ml.get_map(path);

    vector<Player*>* player_vector = new vector<Player*>();
    for (string* player : *(players)) {
        Player* player_model = new Player(*player);

        if (*player == "Aggressive") {
            player_model->setStrategy(new Aggressive());
        } else if (*player == "Benevolent") {
            player_model->setStrategy(new Benevolent());
        } else if (*player == "Random") {
            player_model->setStrategy(new Random());
        } else if (*player == "Cheater") {
            //TODO: missing cheater
        } else {
            cout << "Undefined player strategy." << endl;
        }
        player_vector->push_back(player_model);
    }

    vector<string>* territories = new vector<string>();
    for (Territory* t : game_map->territories) {
        territories->push_back(t->get_name());
    }

    Deck* deck = new Deck(*territories);

    return new Payload(game_map, player_vector, deck);
}

Payload* Start::prompt_start() {
    DIR* dir = opendir("../MapTemplates/");
    struct dirent* entry = nullptr;

    if (dir != nullptr) {
        string path;
        int players = 0;
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

        // asking the user to choose a map
        int mapId;
        do {
            cout << "Please choose one of the following maps." << endl;
            for (int i = 0; i < file_names.size(); i++) {
                cout << i << ") " << file_names[i] << endl;
            }

            string user_input;
            getline(cin, user_input);

            try {
                mapId = stoi(user_input);
            } catch (...) {
                cout << "Invalid input. Please try again." << endl;
                mapId = -1;
            }
        } while (mapId < 0 || mapId >= file_names.size());
        path = "../MapTemplates/" + file_names[mapId];

        // asking for the number of players
        do {
            cout << "How many players will be participating? (2-6)" << endl;
            string user_input;
            getline(cin, user_input);

            try {
                players = stoi(user_input);
            } catch (...) {
                cout << "That is not a valid amount of players. Please try again." << endl;
                players = 0;
            }
        } while(players < 2 || players > 6);

        return start(path, players);
    } else {
        cout << "Unable to open directory.";
        return nullptr;
    }
}