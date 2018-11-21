//
// Created by Michael Wu on 2018-11-17.
//

#ifndef RISK_SUBJECT_H
#define RISK_SUBJECT_H

#include <list>
#include <vector>
#include <string>

#include "../Phase/GamePhase.h"
#include "Observer.h"

class Subject {
private:
    std::list<Observer*>* observers;
public:
    Subject();
    ~Subject();
    virtual void notify(GamePhase data, std::vector<std::string>* event_data = nullptr);
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
};


#endif //RISK_SUBJECT_H
