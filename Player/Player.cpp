#include "Player.h"

using namespace std;

Player::Player() {
    this->PlayerID = -1;
    this->Free_Troops = 0;
    this->cardOnHand = new Hand();
}

Player::Player(int ID) {
    this->PlayerID = ID;
    this->Free_Troops = 0;
    this->cardOnHand = new Hand();
}

Player::~Player() {
	delete this->cardOnHand;
}

void Player::setPID(int id) {this->PlayerID = id;}
int Player::getPID() { return this->PlayerID; }

void Player::setFree_Troops(int num) { this->Free_Troops = num; }
int Player::getFree_troops() { return this->Free_Troops; }

void Player::showcardsonHand() { this->cardOnHand->display_cards(); }

void Player::addTerritory(Territory &x) { this->controlled.push_back(&x); }
//void Player::loseTerritory(Territory &x){}
void Player::showTerritory() {
	for (unsigned int i = 0; i < this->controlled.size(); i++) {
		cout << controlled[i].get_name() << "  ";
	}
}

void Player::attackroll() {
	int tempn;
	do
	{
		cout << "Please choose the number of dices to rool for attack, range from 1~3" << endl;
		cin >> tempn;
		if ((tempn > 0) && (tempn < 4)) {
			D.roll(tempn);
			break;
		}
		else
			cout << "unaccepted entry." << endl;
	} while ( true);
}//roll to attack

void Player::defenceroll() {
	int tempn;
	do
	{
		cout <<"You are being attacked"
			 << "Please choose the number of dices to rool for defence, range from 1~2" << endl;
		cin >> tempn;
		if ((tempn > 0) && (tempn < 3)) {
			D.roll(tempn);
			break;
		}
		else
			cout << "unaccepted entry." << endl;
	} while (true);
}//roll to defend

void Player::round() {
//	this->reinforce();
//	this->attack();
//	this->fortify();
}

void Player::reinforce(){
	cout << "This is the reinforce method" << endl;
	//determine the number of troops to reinforce

	//(check) tard in cards?
	//this->showcardsonHand();//show the cards on hand
	//cardOnHand.exchange();//

	//placing troops

	//end reinforce and call attack

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
		if (att->get_troops() < 2) { cout << "This country has less than 2 armies. Back to main menu."; }
		else
		{
			cout << "choose a neighbor to attack: ";
			vector<Territory*> temp;
			temp = att->get_neighbors();
			vector<Territory*> neighbors;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i]->get_owner()->getPID().compare(PlayerID) != 0) {
					neighbors.push_back(temp[i]);
				}
			}
			for (int i=0;i<neighbors.size();i++) cout << (i + 1) << ". " << neighbors[i]->get_name() << " ";
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

void Player::fortify() {
	cout << "This is the ofrtify method" << endl;
	//get info of territories & dicide if Player will move his troops


	//get a card from Deck and end fortify. let main friver to call the next Player to start his round
	//this->cardOnHand.placeCardInHand();
}

vector<Territory*>& Player::get_own_territories() {
	return this->controlled;
}

void Player::add_troops(int index, int troop) {
    int current_troops = this->controlled[index]->get_troops();
    this->controlled[index]->set_troops(current_troops + troop);

    int current_free_troops = this->getFree_troops();
    this->setFree_Troops(current_free_troops - troop);
}

void Player::fight(Territory* att, Territory* def) {
	int attNum = -1;
	int	defNum = -1;
	for (;;) {
		cout << "choice number of dice to roll (attacker), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
		int tp=att->get_troops() - 1;
		if (tp >= temp)
			if ((temp >= 1) && (temp <= 3)) { attNum = temp; break; }

	}
	for (;;) {
		cout << "choice number of dice to roll (defender), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
		int tp = def->get_troops();
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
			if ((attDice.currentResult[i]) > (defDice.currentResult[i])) def->set_troops(def->get_troops() - 1);
			else if ((attDice.currentResult[i]) == (defDice.currentResult[i])) att->set_troops(att->get_troops() - 1);
			else (att->set_troops(att->get_troops() - 1));
	}

	cout << "Fighting finished !" << endl << "The attacting country "<<att->get_name() <<" now has " << att->get_troops() << " armies." << endl
		 <<"The defending country "<<def->get_name()<<" now has "<<def->get_troops()<<" armies."<<endl;

	if (def->get_troops() == 0) {
		cout << "Defending country " << def->get_name() << " has no army now, it now belongs to "<<att->get_owner()->getPID()<<endl;
		def->set_owner(att->get_owner());
		this->addTerritory(*def);
	}

}

void Player::movingArmy() {

	for (;;) {
		cout << "Player " << PlayerID << " now has:" << endl;
		for (int i = 0; i < controlled.size(); i++) {
			cout << "country: " <<i+1<<"."<<controlled[i]->get_name() << ". Army:" << controlled[i]->get_troops()<<endl;
		}
		cout << "choose move from (enter index): "; int mf; cin >> mf; cout << endl;
		if ((mf > controlled.size()) || (mf < 1)) { cout << "country number invalid,going back."<<endl; continue; }
		cout << "choose move to (enter index): "; int mt; cin >> mt; cout << endl;
		if ((mt > controlled.size()) || (mt < 1)) { cout << "country number invalid,going back."<<endl; continue; }
		if (mf == mt) { cout << "Please dont't move armies from one country to itself."<<endl; continue; }
		cout << "enter the number of armies to move: "; int toMove; cin >> toMove; cout << endl;
		if (toMove >= controlled[mf - 1]->get_troops()) { cout << "You can only move " << (controlled[mf - 1]->get_troops() - 1) << " armies from " << controlled[mf - 1]->get_name() << endl; continue; }


		controlled[mf - 1]->set_troops(controlled[mf - 1]->get_troops() - toMove);
		controlled[mt - 1]->set_troops(controlled[mt - 1]->get_troops() + toMove);
		cout << "finished moving...."<<endl;
		cout << "Player " << PlayerID << " now has:" << endl;
		for (int i = 0; i < controlled.size(); i++) {
			cout << "country: " << i + 1 << "." << controlled[i]->get_name() << ". Army:" << controlled[i]->get_troops() << endl;
		}
		break;
	}
}
