#pragma once
#include "../Map/Map.h"
#include "../Deck/Hand.h"

class Player;

class Fortification {
private:
    Player* ptemp;


    bool fortificate1(Territory* take);
    bool fortificate2(Territory* take, int re);

public:
    Fortification();
    Fortification(Player &P);
    void fortificate();
};