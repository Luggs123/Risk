//edited by YINGJIE ZHOU
#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "../Dice/Dice.h"
#include "../Map/Map.h"
#include "../Deck/Hand.h"
#include "../Phase/Fortification.h"
#include "../Phase/Reinforcement.h"

class Player {

private:
	//int check_reinforceAmout();// ToDo: calculate the number of troops a Player get
	int check_continents();// ToDo: check if this Player owned continents
	int get_troops(/*Territory*/int &x);// TODO: get the amount of troops for a specific territory
	std::vector<Territory*> controlled;// a vector of Territories owned by Player

    int PlayerID;
    std::string player_name;
    int free_troops;//the number of troops player can placed as they want
    Hand* card_on_hand; //the Object that takes the player's cards on hand
    Dice D;// the DICE Object for the player
	Reinforcement* reinforcement = nullptr;
    Fortification* fortification = nullptr;

public:
	Player();
    Player(std::string n); //constructor
	~Player();
	void round();

	void setPID(int ID);
	int getPID();
    void set_name(std::string n);
    void show_name();
	void set_free_troops(int num);
	int get_free_troops();
	void showcardsonHand();

	void add_territory(Territory &x);//add new territory that Player just occupied
	void lose_territory(Territory &x);//remove the territory that Player just lose
	void show_territory();
	void attackroll();
	void defenceroll();
    std::vector<Territory*>& get_own_territories();
	void add_troops(int index, int troop);

	void reinforce();
	void attack();
	void fortify();

	void fight(Territory* att, Territory* def);
	void movingArmy();

    Territory* get_controlled();
    int get_number_controlled();
};