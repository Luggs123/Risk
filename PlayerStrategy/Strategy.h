#pragma once

class Player;

class Strategy {
public:
    virtual void execute(Player* p) = 0;
};