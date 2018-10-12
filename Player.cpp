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

void Player::addTerritory(Territory &x) { this->controlled.push_back(x); }
void Player::loseTerritory(Territory &x){}

void Player::reinforce(){
	//determine the number of troops to reinforce

	//(check) tard in cards?
	this->showcardsonHand();//show the cards on hand
	//cardOnHand.exchange();//

	//placing troops

	//end reinforce and call attack

}

void Player::attack() {
	//get info of territories & choose the origin and destionation of attack

	//roll the dice both attacker and defender

	//get result

	//continue attack or end it

}

void Player::fortify() {

	//get info of territories & dicide if player will move his troops


	//get a card from deck and end fortify. let main friver to call the next player to start his round
	//this->cardOnHand.placeCardInHand();
}
