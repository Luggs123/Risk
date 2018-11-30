// Assignment 4, Part 1: Cheater Player Strategy
// Written by Michael Luger, 40055539

#ifndef CHEATER_H
#define CHEATER_H

#include "Strategy.h"

class Cheater : public Strategy {
public:
	void execute(Player* p);
};

#endif