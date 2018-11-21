#include "GameStaticsSubject.h"

GameStaticsSubject::GameStaticsSubject() {
	this->_observers = new list<GameStaticsObserver*>;
}
GameStaticsSubject::~GameStaticsSubject() {
	delete this->_observers;
}

void GameStaticsSubject::attach(GameStaticsObserver* gso) {
	this->_observers->push_back(gso);
}

void GameStaticsSubject::detach(GameStaticsObserver* gso) {
	this->_observers->remove(gso);
}

void GameStaticsSubject::notify() {
	
	list<GameStaticsObserver *>::iterator i = this->_observers->begin();
	for (; i != this->_observers->end(); ++i)
		(*i)->update();
}


