#pragma once

#include <vector>
#include <string>

using namespace std;

class Player;

class Territory {
private:
	Player* owner;
	string name;
	int troops;
	vector<Territory*> neighbors;

public:
	Territory(string name);
	Territory(string na, int trp, Player* owner);

	// Accessors
	int getTroops();
	string getName();
	vector<Territory*> getNeighbors();
	Player* getOwner();


	// Mutators
	void setOwner(Player* owner);
	void setTroops(int troops);
	void addNeighbor(Territory* t);

};

class Player {

private:
	vector<Territory *> controlled;
	string PlayerID;


public:
	Player();
	Player(string id);
	string getId();
	void setId(int id);
	void attack();
	void addTerritory(Territory* x);
	void showTerritory();

	void fight(Territory* att, Territory* def);
	void movingArmy();
};

class Dice {

public:
	string name;
	Dice();
	Dice(string nam);
	int totalRolled;
	int currentRolled;
	int currentResult[3];
	int diceStats[7];
	void getPercentage();
	void roll(int num);
	void game();
	void sortResult();
};


