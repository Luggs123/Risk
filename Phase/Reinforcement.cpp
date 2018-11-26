#include "Reinforcement.h"
#include "../Player/Player.h"

using namespace std;

//default constructor
Reinforcement::Reinforcement() {
    this->num_troop = 0;
}

//constructor
Reinforcement::Reinforcement(Player &p) {
    this->ptemp = &p;
    this->num_troop = 0;
}

void Reinforcement::run_reinforcement(Map &ma) {
    num_controlled = ptemp->get_number_controlled();
    if (num_controlled == 0)
        cout << "no controlled Territory" << endl;
    else {
        this->cal_num_troop();
        this->reinforce();
    }
}


void Reinforcement::run_reinforcement() {
    num_controlled = ptemp->get_number_controlled();
    if (num_controlled == 0)
        cout << "no controlled Territory" << endl;
    else {
		this->cal_num_troop();
        this->reinforce();
    }
}

void Reinforcement::cal_num_troop() {
	this->controlled = this->ptemp->get_own_territories();
    this->num_troop = (int)(num_controlled / 3);
	if (this->num_troop < 3) {
		this->num_troop = 3;
	}
	this->check_continent();
	this->num_troop += this->ptemp->check_hand();
}

void Reinforcement::check_continent() {
	vector<Continent*> _continent;//a vector to store the continents related to current player
	int owned_territory_num = this->ptemp->get_number_controlled();
	//fetching the related continents 
	for (int i = 0; i < owned_territory_num; i++) {
		if (_continent.size() == 0) {
			_continent.push_back((this->ptemp->get_own_territories())[i]->get_continent());
			continue;
		}
		for (int j = 0; j < _continent.size(); j++) {
				if ((_continent[j]->get_name().compare(this->ptemp->get_own_territories()[i]->get_continent()->get_name())) != 0) {
					if ((j + 1) == _continent.size()) {
						_continent.push_back(this->ptemp->get_own_territories()[i]->get_continent());
						break;
					}
				}
				
			

		}//for j, the No. of related continent
	}//for i, the NO. of controlled territories
	//checking each related continent if it is fully controlled by current player
	for (int i = 0; i < _continent.size(); i++) {
		for (int j = 0; j < _continent[i]->get_territories().size(); j++) {
			if ((_continent[i]->get_territories()[j]->get_owner()->getPID().compare(this->ptemp->getPID())) != 0) {
				break;
			}
			else
			{
				if ((j + 1) == _continent[i]->get_territories().size()) {
					this->num_troop += _continent[i]->get_value();
				}
			}
		}//for j, No. of territory in a continent
	}//for i, No. of related continent


}

void Reinforcement::check_hand() {
    ptemp->showcardsonHand();
    //TODO
}

void Reinforcement::reinforce() {
    while (this->num_troop > 0) {
        cout << "Time to reinforece your Territory." << endl
             << "You have " << this->num_troop << " troops to reinforce." << endl
             << "Please select the territory number you want to reinforce :" << endl;
		this->controlled = this->ptemp->get_own_territories();
        for (int i = 0; i < this->num_controlled; i++) {
			cout << i << ". " << (*controlled[i]).get_name() << " with " << (*controlled[i]).get_troops() << " troops." << endl;
        }
        int in;
        cin >> in;
        if (in >= 0 && in < this->num_controlled) {
            this->add_troops(controlled[in]);
        }
        else
            cout << "invalid input." << endl
                 << "------------------------------------------" << endl;
    }//end while
}

void Reinforcement::add_troops(Territory* t) {
    cout << "Please select the number of troops to reinforce to territory " << t->get_name() <<". Range from 1 to " << this->num_troop << endl;
    int re;
    cin >> re;
    if (re > 0 && re <= this->num_controlled)
    {
        t->set_troops(t->get_troops() + re);
        this->num_troop = num_troop - re;

        vector<string> data_str = {t->get_name(), to_string(re)};
        ptemp->notify(GamePhase::REINFORCEMENT, &data_str);
    }
    else
        cout << "Invalid input. Please choose again" << endl;
}

