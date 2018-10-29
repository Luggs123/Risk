#include "Player.h"

Player::Player() {
	this->PlayerID = -1;
	this->Free_Troops = 0;
	
	
}

void Player::setPID(int id) {this->PlayerID = id;}
int Player::getPID() { return this->PlayerID; }

void Player::setFree_Troops(int num) { this->Free_Troops = num; }
int Player::getFree_troops() { return this->Free_Troops; }

void Player::showcardsonHand() { this->cardOnHand.displayCards(); }

void Player::addTerritory(Territory_Test &x) { this->controlled.push_back(x); }
//void Player::loseTerritory(Territory &x){}
void Player::showTerritory() {
	for (unsigned int i = 0; i < this->controlled.size(); i++) {
		cout << controlled[i].getname() << "  ";
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

void Player::defencerool() {
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
	this->reinforce();
	this->attack();
	this->fortify();
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
	cout << "This is the attack method" << endl;
	//get info of territories & choose the origin and destionation of attack

	//roll the dice both attacker and defender

	//get result

	//continue attack or end it

}

void Player::fortify() {
	cout << "This is the ofrtify method" << endl;
	//get info of territories & dicide if player will move his troops


	//get a card from deck and end fortify. let main friver to call the next player to start his round
	//this->cardOnHand.placeCardInHand();
}
