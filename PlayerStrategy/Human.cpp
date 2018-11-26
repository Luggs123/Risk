// Assignment 3, Part 1: Human Player Strategy
// Written by Michael Luger, 40055539

#include <iostream>
#include <string>
#include "../Player/Player.h"
#include "Human.h"
#include "../Phase/Reinforcement.h"

using namespace std;

void Human::execute(Player* p) {
	cout << "Human strategy executed." << endl;
	cout << "Player " << p->getPID() << " currently owns the following:" << endl;
	p->show_territory();
	cout << endl;

	reinforce(p);
	attack(p);
	fortify(p);
	cout << "End of turn." << endl;
}

void Human::reinforce(Player* p) {
	Reinforcement* reinforce = new Reinforcement(*p);
	reinforce->run_reinforcement();
}

void Human::attack(Player* p) {
	string response;

	while (true) {
		cout << "Do you want to attack? (y/n)" << endl;
		cin >> response;
		transform(response.begin(), response.end(), response.begin(), ::tolower);

		if (response.compare("n") == 0) {
			break;
		}
		else if (response.compare("y") == 0) {
			cout << "Which territory do you want to attack with? (\"Cancel\" to cancel)" << endl;
			cin >> response;
			transform(response.begin(), response.end(), response.begin(), ::tolower);

			if (response.compare("cancel") == 0) {
				continue;
			}

			Territory *atk=nullptr, *def=nullptr;
			bool found = false, can_attack = false;
			for (Territory* t : p->get_own_territories()) {
				string name = t->get_name();
				transform(name.begin(), name.end(), name.begin(), ::tolower);
				if (name.compare(response) == 0) {
					atk = t;
					if (t->get_owner() != p) {
						cout << "You do not own this territory." << endl;
						continue;
					}
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "That territory does not exist." << endl;
				continue;
			}

			found = false;
			cout << "Which territory do you want to attack? (Cancel to cancel)" << endl;
			cin >> response;
			transform(response.begin(), response.end(), response.begin(), ::tolower);

			if (response.compare("cancel") == 0) {
				continue;
			}

			for (Territory* t : atk->get_neighbors()) {
				string name = t->get_name();
				transform(name.begin(), name.end(), name.begin(), ::tolower);
				if (name.compare(response) == 0) {
					def = t;
					found = true;
					if (t->get_owner() == p) {
						cout << "You cannot attack your own territory." << endl;
						continue;
					}
					else {
						can_attack = true;
						break;
					}
				}
			}
			if (!found) {
				cout << "That territory does not exist adjacent to the attacking territory." << endl;
				continue;
			}
			if (can_attack) {
				p->fight(atk, def);
			}
		}
		else {
			continue;
		}
	}
}

void Human::fortify(Player* p) {
	string response;
	cout << "Do you want to fortify a territory? (y/n)" << endl;
	cin >> response;
	transform(response.begin(), response.end(), response.begin(), ::tolower);

	if (response.compare("n") == 0) {
		return;
	}
	else if (response.compare("y") != 0) {
		fortify(p);
		return;
	}
	else {
		Territory *origin=nullptr, *target=nullptr;
		cout << "Which territory would you like to transfer troops from?" << endl;
		cin >> response;
		transform(response.begin(), response.end(), response.begin(), ::tolower);

		bool found = false;
		string name;

		for (Territory* t : p->get_own_territories()) {
			name = t->get_name();
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			if (name.compare(response) == 0) {
				found = true;
				origin = t;
			}
		}

		if (!found) {
			cout << "You do not own a territory by that name." << endl;
			fortify(p);
			return;
		}

		cout << "Which territory would you like to transfer troops to?" << endl;
		cin >> response;
		transform(response.begin(), response.end(), response.begin(), ::tolower);

		found = false;
		for (Territory* t : origin->get_neighbors()) {
			name = t->get_name();
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			if (name.compare(response) == 0) {
				found = true;
				if (t->get_owner() != p) {
					cout << "You do not own this territory." << endl;
					fortify(p);
					return;
				}
				target = t;
			}
		}

		if (!found) {
			cout << "You do not own a territory by that name." << endl;
			fortify(p);
			return;
		}
		else {
			cout << "How many troops would you like to transfer?" << endl;
			cin >> response;
			int troops = stoi(response);
			if (troops > origin->get_troops() - 1) {
				cout << "You do not have enough troops in the origin territory to transfer." << endl;
			}
			else {
				origin->set_troops(origin->get_troops() - troops);
				target->set_troops(target->get_troops() + troops);
				cout << troops << " troops transferred from " << origin->get_name() << " to " << target->get_name() << "." << endl;
			}
		}
	}
}