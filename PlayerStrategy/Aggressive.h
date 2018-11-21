// Assignment 3, Part 1: Aggressive Player Strategy
// Written by Michael Luger, 40055539

#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H

#include "Strategy.h"

class Aggressive : public Strategy {
public:
	void execute(Player* p);
};

#endif