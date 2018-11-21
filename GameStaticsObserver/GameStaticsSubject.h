#pragma once
#include "GameStaticsObserver.h"
#include <list>

using namespace std;

//class GameStaticsObserver;

class GameStaticsSubject {
  public:
	virtual void attach(GameStaticsObserver* o);
	virtual void detach(GameStaticsObserver* o);
	virtual void notify();
	GameStaticsSubject();
	~GameStaticsSubject();
  private:
	list<GameStaticsObserver*> *_observers;
};