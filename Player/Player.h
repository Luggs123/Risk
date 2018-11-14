//edited by YINGJIE ZHOU
#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "../Dice/Dice.h"
#include "../Map/Map.h"
#include "../Deck/Hand.h"

class Player {

private:
	//int check_reinforceAmout();// ToDo: calculate the number of troops a Player get
	int check_continents();// ToDo: check if this Player owned continents
	int get_troops(/*Territory*/int &x);// TODO: get the amount of troops for a specific territory
	std::vector<Territory*> controlled;// a vector of Territories owned by Player
	
	

	int PlayerID;
	int Free_Troops;//the number of troops Player can placed as they want
	Hand* cardOnHand; //the Object that takes the Player's cards on hand
	Dice D;// the DICE Object for the Player


public:
	Player();
	Player(int ID);
	~Player();
	void round();

	void setPID(int ID);
	int getPID();
	void setFree_Troops(int num);
	int getFree_troops();
	void showcardsonHand();

	void addTerritory(Territory &x);//add new territory that Player just occupied
	//void loseTerritory(Territory &x);//remove the territory that Player just lose
	void showTerritory();
	void attackroll();
	void defenceroll();
    std::vector<Territory*>& get_own_territories();
	void add_troops(int index, int troop);

	void reinforce();
	void attack();
	void fortify();

	void fight(Territory* att, Territory* def);
	void movingArmy();
};