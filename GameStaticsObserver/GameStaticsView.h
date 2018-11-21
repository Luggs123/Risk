#pragma once
#include "GameStaticsObserver.h"
#include"../Map/Map.h"

class GameStaticsView : public GameStaticsObserver {
public:
	
	GameStaticsView(Map* ma);//attaching
	~GameStaticsView();
	void update();//being called and updating view
	void display();//display info
private:
	GameStaticsView();
	Map *_subject;
};