//
// Created by Michael Wu on 2018-11-17.
//

#ifndef RISK_OBSERVER_H
#define RISK_OBSERVER_H

#include "../Phase/GamePhase.h"

class Observer {
public:
    ~Observer();
    virtual void update(GamePhase data) = 0;

protected:
    Observer() { };
};


#endif //RISK_OBSERVER_H
