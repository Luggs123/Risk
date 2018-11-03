#pragma once
#include <vector>
#include <iostream>
#include <string>

#include "../Dice/dice.h"
#include "../Cards/Hand.h"
class Territory;

using namespace std;

class Player {

private:
	//int check_reinforceAmout();// ToDo: calculate the number of troops a player get
	int check_continents();// ToDo: check if this player owned continents
	int get_troops(/*Territory*/int &x);// TODO: get the amount of troops for a specific territory
	void add_troops(/*Territory*/int &x);// TODO: add troops to a specific territory
	vector<Territory*> controlled;// a vector of Territories owned by player
	
	

	int PlayerID;
	int Free_Troops;//the number of troops player can placed as they want
	Hand* cardOnHand; //the Object that takes the player's cards on hand
	dice D;// the DICE Object for the player

	void reinforce();
	void attack();
	void fortify();

public:
	Player();
	Player(int ID);
	void round();

	void setPID(int ID);
	int getPID();
	void setFree_Troops(int num);
	int getFree_troops();
	void showcardsonHand();
	

	void addTerritory(Territory* x);//add new territory that player just occupied
	void loseTerritory(Territory* x);//remove the territory that player just lose
	void showTerritory();
	void attackroll();
	void defenceroll();
};