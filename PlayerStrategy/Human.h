// Assignment 3, Part 1: Human Player Strategy
// Written by Michael Luger, 40055539

#ifndef HUMAN_H
#define HUMAN_H

#include "Strategy.h"

class Human : public Strategy {
public:
	void execute(Player* p);
private:
	void reinforce(Player* p);
	void attack(Player* p);
	void fortify(Player* p);
};

#endif