#pragma once
#include"vector"
#include"iostream"
#include"string"

#include "dice.h"
#include "Map.h"
#include "Hand.h"

#include"Territory_Test.h"
/*change for A2 by YINGJIE ZHOU
* 1, playerID(int) replaced by player_name, getPID() replaced by show_name()
* 2, add function which return the address of this player, named get_player()
* 3, add constructors
*/
using namespace std;

class Player {

private:
	//int check_reinforceAmout();// ToDo: calculate the number of troops a player get
	//int check_continents();// ToDo: check if this player owned continents
	int get_troops(Territory &x);// TODO: get the amount of troops for a specific territory
	void add_troops(Territory &x, int n);// TODO: add troops to a specific territory
	vector<Territory_Test> controlled;// a vector of Territories owned by player
	
	

	int PlayerID;
	string player_name;
	int free_troops;//the number of troops player can placed as they want
	Hand cardOnHand; //the Object that takes the player's cards on hand
	dice D;// the DICE Object for the player

	void reinforce();
	void attack();
	void fortify();

public:
	Player();//default constructor
	Player(string n);//constructor
	void round();

	void setPID(int ID);//old
	int getPID();//old
	void set_name(string n);
	void show_name();
	void setfree_troops(int num);
	int getfree_troops();
	void showcardsonHand();
	

	void addTerritory(Territory_Test &x);//add new territory that player just occupied
	//void loseTerritory(Territory &x);//remove the territory that player just lose
	void showTerritory();
	void attackroll();
	void defencerool();
};