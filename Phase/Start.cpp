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
        playerVector->push_back(new Player(i + 1));
    }

    vector<string>* territories = new vector<string>();
    for (Territory* t : game_map->territories) {
        territories->push_back(t->get_name());
    }

    Deck* deck = new Deck(*territories);

    return new Payload(game_map, playerVector, deck);
}

Payload* Start::prompt_start() {
    string path;
    cout << "Please select a .map file to be used for this game." << endl;
    cin >> path;

    int players;
    cout << "How many players will be participating? (2-6)" << endl;

    while (true) {
        try {
            string pl;
            cin >> pl;
            players = stoi(pl);
            if (players < 2 || players > 6) {
                cout << "That is not a valid amount of players. Please try again." << endl;
            }
            else {
                break;
            }
        }
        catch (invalid_argument) {
            cout << "That is not a number. Please try again." << endl;
        }
    }

    return start(path, players);
}