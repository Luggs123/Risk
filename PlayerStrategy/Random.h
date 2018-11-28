// Assignment 4 by Ma,Ke.

#pragma once

#include "Strategy.h"

class Random : public Strategy {
public:
    void execute(Player* p);
};