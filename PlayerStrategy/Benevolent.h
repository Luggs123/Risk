#pragma once

#include "Strategy.h"

class Benevolent : public Strategy {
public:
    void execute(Player* p);
};