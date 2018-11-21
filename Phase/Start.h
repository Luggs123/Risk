// Assignment 2, Part 1: Game Start
// Written by Michael Luger, 40055539

#ifndef START_H
#define START_H

#include <iostream>
#include <string>
#include "../INCLUDE/dirent.h"

#include "../Map/MapLoader.h"
#include "../View/View.h"
#include "Payload.h"

class Start {
private:
    Start() { }
public:
    static Payload* start(std::string path, int players);
    static Payload* prompt_start();
};

#endif