
#include <iostream>
#include "Attack.h"


Player::Player() {
	this->PlayerID = -1;
}
Player::Player(string id) :PlayerID(id) {

}

string Player::getId() {
	return PlayerID;
}

void Player::setId(int id) {
	PlayerID = id;
}

void Player::addTerritory(Territory* x) { this->controlled.push_back(x); }


void Player::showTerritory() {
	for (unsigned int i = 0; i < this->controlled.size(); i++) {
		cout <<(i+1)<<". "<< controlled[i]->getName() << " ";
	}
}


void Player::attack() {
	Territory* att;
	Territory* def;
	
		cout << "choose your countries to attack from." << endl;
		this->showTerritory(); cout << endl;
		int choice;
		cin >> choice;
		if ((choice >= 1) && (choice <= controlled.size())) {
			att = controlled[choice - 1];
			if (att->getTroops() < 2) { cout << "This country has less than 2 armies. Back to main menu."; }
			else
			{
				cout << "choose a neighbor to attack: ";
				vector<Territory*> temp;
				temp = att->getNeighbors();
				vector<Territory*> neighbors;
				for (int i = 0; i < temp.size(); i++) { 
					if (temp[i]->getOwner()->getId().compare(PlayerID) != 0) {
						neighbors.push_back(temp[i]); 
					}		
				}
				for (int i=0;i<neighbors.size();i++) cout << (i + 1) << ". " << neighbors[i]->getName() << " ";
				int num;
				cin >> num;
				num--;
				if ((num > (neighbors.size() - 1)) || (num < 0)) cout << "invalid index.";
				else {
					def = neighbors[num];
					this->fight(att, def);
				}
			}
		}
	
}

void Player::fight(Territory* att, Territory* def) {
	int attNum = -1;
	int	defNum = -1;
	for (;;) {
		cout << "choice number of dice to roll (attacker), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
		int tp=att->getTroops() - 1;
		if (tp >= temp)
			if ((temp >= 1) && (temp <= 3)) { attNum = temp; break; }
		
	}
	for (;;) {
		cout << "choice number of dice to roll (defender), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
		int tp = def->getTroops();
		if (tp >= temp)
			if ((temp >= 1) && (temp <= 2)) {defNum = temp; break;}
	}

	Dice attDice, defDice;

	attDice.roll(attNum);
	defDice.roll(defNum);
	attDice.sortResult();
	defDice.sortResult();

	for (int i = 0; i < 3; i++) {
		if ((attDice.currentResult[i] != 0 ) && (defDice.currentResult[i] != 0 )) 
			if ((attDice.currentResult[i]) > (defDice.currentResult[i])) def->setTroops(def->getTroops() - 1);
			else if ((attDice.currentResult[i]) == (defDice.currentResult[i])) att->setTroops(att->getTroops() - 1);
			else (att->setTroops(att->getTroops() - 1));
	}

	cout << "Fighting finished !" << endl << "The attacting country "<<att->getName() <<" now has " << att->getTroops() << " armies." << endl
		<<"The defending country "<<def->getName()<<" now has "<<def->getTroops()<<" armies."<<endl;

	if (def->getTroops() == 0) { 
		cout << "Defending country " << def->getName() << " has no army now, it now belongs to "<<att->getOwner()->getId()<<endl;
		def->setOwner(att->getOwner()); 
		this->addTerritory(def); 
	}

}

void Player::movingArmy() {

	for (;;) {
		cout << "Player " << PlayerID << " now has:" << endl;
		for (int i = 0; i < controlled.size(); i++) {
			cout << "country: " <<i+1<<"."<<controlled[i]->getName() << ". Army:" << controlled[i]->getTroops()<<endl;
		}
		cout << "choose move from (enter index): "; int mf; cin >> mf; cout << endl;
		if ((mf > controlled.size()) || (mf < 1)) { cout << "country number invalid,going back."<<endl; continue; }
		cout << "choose move to (enter index): "; int mt; cin >> mt; cout << endl;
		if ((mt > controlled.size()) || (mt < 1)) { cout << "country number invalid,going back."<<endl; continue; }
		if (mf == mt) { cout << "Please dont't move armies from one country to itself."<<endl; continue; }
		cout << "enter the number of armies to move: "; int toMove; cin >> toMove; cout << endl;
		if (toMove >= controlled[mf - 1]->getTroops()) { cout << "You can only move " << (controlled[mf - 1]->getTroops() - 1) << " armies from " << controlled[mf - 1]->getName() << endl; continue; }


		controlled[mf - 1]->setTroops(controlled[mf - 1]->getTroops() - toMove);
		controlled[mt - 1]->setTroops(controlled[mt - 1]->getTroops() + toMove);
		cout << "finished moving...."<<endl;
		cout << "Player " << PlayerID << " now has:" << endl;
		for (int i = 0; i < controlled.size(); i++) {
			cout << "country: " << i + 1 << "." << controlled[i]->getName() << ". Army:" << controlled[i]->getTroops() << endl;
		}
		break;
	}
}