#include"GameStaticsView.h"
#include"../Player/Player.h"

#include <iomanip>
#include <math.h>

using namespace std;

GameStaticsView::GameStaticsView() {

};

GameStaticsView::GameStaticsView(Map* ma) {
	//instantiation, attach itself to a Map
	this->_subject = ma;
	for (int i = 0; i < this->_subject->territories.size(); i++) {
		this->_subject->territories[i]->attach(this);
	}
	
}

GameStaticsView::~GameStaticsView() {

//destruction
	for (int i = 0; i < this->_subject->territories.size(); i++) {
		this->_subject->territories[i]->detach(this);
	}
}

void GameStaticsView::update() {
	display();
}

void GameStaticsView::display() {
	int num_territory = this->_subject->territories.size();//get the number of territories

	//fetching a current player vector
	vector<Player*> players;
	for (int i = 0; i < num_territory; i++) {
		if (i == 0) {
			players.push_back(this->_subject->territories[i]->get_owner());
			
		}
		else {
			for (int j = 0; j < players.size(); j++) {
				if (!(players[j]->getPID().compare(this->_subject->territories[i]->get_owner()->getPID())))
					break;
				if ((j + 1) >= players.size()) {
					players.push_back(this->_subject->territories[i]->get_owner());
					break;
				}
			}//end for
		}
	}//end for

	switch (players.size()) {
	case 0:
		cout << "error" << endl;
		break;
	case 1:
		if (players[0]->get_number_controlled() == num_territory)
			cout << "Congratulation! The Player " << players[0]->getPID() << " occupied all territories!" << endl
			<< players[0]->getPID() << " is the winner!" << endl;
		else
			cout << "there is only one player left, which is " << players[0]->getPID() << "." << endl
			<< "But he has not occupied all territories." << endl;
		break;
	default:
		for (int j = 0; j < players.size(); j++) {
			int percent = round((players[j]->get_number_controlled() / (double)num_territory) * 100);//counting the percentage occupied by specified player


			cout << "Player " << players[j]->getPID() << " has occupied " << players[j]->get_number_controlled() << " territories.    Which is " << std::to_string(percent) << "% of all territories in the current Map."<<endl;
		}

	}//end switch
}