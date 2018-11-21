#pragma once

#include <iostream>

class GameStaticsObserver {
public:
	~GameStaticsObserver();
	virtual void update() = 0;
protected:
	GameStaticsObserver();
};