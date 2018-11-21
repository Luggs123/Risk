//
// Created by Michael Wu on 2018-11-17.
//

#include "Subject.h"
#include "Observer.h"

using namespace std;

Subject::Subject() {
    this->observers = new list<Observer*>;
}

Subject::~Subject() {
    delete this->observers;
}

void Subject::attach(Observer* observer) {
    this->observers->push_back(observer);
}

void Subject::detach(Observer *observer) {
    this->observers->remove(observer);
}

void Subject::notify(GamePhase data, vector<string>* event_data) {
    for (auto &observerObj : *(this->observers)) {
        observerObj->update(data, event_data);
    }
}