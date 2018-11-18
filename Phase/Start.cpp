// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#include "Start.h"

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
    for (int i = 0; i < players; i++) {
        playerVector->push_back(new Player(to_string(i + 1)));
    }

    vector<string>* territories = new vector<string>();
    for (Territory* t : game_map->territories) {
        territories->push_back(t->get_name());
    }

    Deck* deck = new Deck(*territories);

    return new Payload(game_map, playerVector, deck);
}

Payload* Start::prompt_start() {
    DIR* dir = opendir("../MapTemplates/");
    struct dirent* entry = nullptr;

    if (dir != nullptr) {
        string path;
        int players = 0;
        vector<string> fileNames;

        // fetching the list of maps
        entry = readdir(dir);
        while(entry != nullptr) {
            fileNames.emplace_back(entry->d_name);
            entry = readdir(dir);
        }
        closedir(dir);

        // removing entries . and ..
        fileNames.erase(fileNames.begin());
        fileNames.erase(fileNames.begin());

        // asking the user to choose a map
        int mapId;
        do {
            cout << "Please choose one of the following maps." << endl;
            for (int i = 0; i < fileNames.size(); i++) {
                cout << i << ") " << fileNames[i] << endl;
            }

            string userInput;
            getline(cin, userInput);

            try {
                mapId = stoi(userInput);
            } catch (...) {
                cout << "Invalid input. Please try again." << endl;
                mapId = -1;
            }
        } while (mapId < 0 || mapId >= fileNames.size());
        path = "../MapTemplates/" + fileNames[mapId];

        // asking for the number of players
        do {
            cout << "How many players will be participating? (2-6)" << endl;
            string userInput;
            getline(cin, userInput);

            try {
                players = stoi(userInput);
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