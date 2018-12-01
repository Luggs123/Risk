#include "Player.h"

using namespace std;

Player::Player() {
    this->player_id = "Default Player";
    this->free_troops = 0;
    this->card_on_hand = new Hand();
}

Player::Player(string n) {
    this->player_id = n;
    this->free_troops = 0;
    this->card_on_hand = new Hand();
}

Player::~Player() {
	delete this->card_on_hand;
	delete this->fortification;
	delete this->reinforcement;
}

Player::Player(string id, Strategy* init): player_id(id) , strategy(init){

}
void Player::setStrategy(Strategy *newStrategy) {
    strategy = newStrategy;

}
void Player::executeStrategy() {
    strategy->execute(this);

}

void Player::setPID(string &id) {this->player_id = id;}
string& Player::getPID() { return this->player_id; }

int Player::get_troops(Territory &x) {
	return x.get_troops();
}
void Player::add_troops(Territory &x, int n) {
	x.set_troops(x.get_troops() + n);
}

void Player::set_free_troops(int num) { this->free_troops = num; }
int Player::get_free_troops() { return this->free_troops; }

void Player::showcardsonHand() { this->card_on_hand->display_cards(); }
void Player::set_deck(Deck* D) { this->card_on_hand->set_deck(D); }

void Player::add_territory(Territory* x) { this->controlled.push_back(x); x->set_owner(this);}

void Player::lose_territory(Territory* x){
	if (this->controlled.size() == 0)
		cout << "error" << endl;
	else {
		for (int i = 0; i < this->controlled.size(); i++) {
			if (!(controlled[i]->get_name().compare(x->get_name()))) {
				vector<Territory*>::iterator iter = controlled.begin()+i;
				controlled.erase(iter);
				break;
			}
			if ((i + 1) >= controlled.size())
				cout << "Error: Territory not found" << endl;

		}
	}
}

void Player::show_territory() {
	for (unsigned int i = 0; i < this->controlled.size(); i++) {
		cout << controlled[i]->get_name() << "  ";
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
    notify(GamePhase::REINFORCEMENT);
	if (this->reinforcement == nullptr)
		this->reinforcement = new Reinforcement(*this);

	this->reinforcement->run_reinforcement();
}

void Player::attack() {
	notify(GamePhase::ATTACK);
	Territory* att;
	Territory* def;
	bool invalid_input = true;

	while (invalid_input) {
        cout << "choose your countries to attack from." << endl;

        for (int i = 0; i < controlled.size(); i++) {
            cout << i << ". " << controlled[i]->get_name() << endl;
        }

        int choice;
        cin >> choice;
        if ((choice >= 0) && (choice < controlled.size())) {
            att = controlled[choice];

            if (att->get_troops() < 2) {
                cout << "This country has less than 2 armies. Back to main menu." << endl;
            } else {
                cout << "choose a neighbor to attack: " << endl;
                vector<Territory *> temp;
                temp = att->get_neighbors();
                vector<Territory *> neighbors;
                for (int i = 0; i < temp.size(); i++) {
                    if (temp[i]->get_owner()->getPID().compare(player_id) != 0) {
                        neighbors.push_back(temp[i]);
                    }
                }
                for (int i = 0; i < neighbors.size(); i++) {
                    cout << (i + 1) << ". " << neighbors[i]->get_name() << " " << endl;
                }
                int num;
                cin >> num;
                num--;
                if ((num > (neighbors.size() - 1)) || (num < 0)) {
                    cout << "invalid index.";
                } else {
                    invalid_input = false;
                    def = neighbors[num];
                    this->fight(att, def);
                }
            }
        }

    }
}

void Player::fortify() {
    notify(GamePhase::FORTIFY);

	if (this->fortification == nullptr)
		this->fortification = new Fortification(*this);

	this->fortification->fortificate();
	this->card_on_hand->add_card_on_hand();
}

vector<Territory*>& Player::get_own_territories() {
	return this->controlled;
}

void Player::add_troops(int index, int troop) {
    int current_troops = this->controlled[index]->get_troops();
    this->controlled[index]->set_troops(current_troops + troop);

    int current_free_troops = this->get_free_troops();
    this->set_free_troops(current_free_troops - troop);
}

void Player::fight(Territory* att, Territory* def) {
    vector<string> data_str = {def->get_name(), att->get_name()};
    notify(GamePhase::ATTACK, &data_str);
	int attNum = -1;
	int	defNum = -1;
	int atk_roll = 3;
	for (;;) {
//		cout << "choice number of dice to roll (attacker), repeat if the number is invalid" << endl;
		int temp = atk_roll; // automated
//		cin >> temp; cout << endl;
		int tp=att->get_troops() - 1;
		if (tp >= temp)
			if ((temp >= 1) && (temp <= 3)) { attNum = temp; break; }

		atk_roll--;
	}
	for (;;) {
//		cout << "choice number of dice to roll (defender), repeat if the number is invalid" << endl;
		int temp = 1; // automated
//		cin >> temp; cout << endl;
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
			if ((attDice.currentResult[i]) > (defDice.currentResult[i]))
				def->set_troops(def->get_troops() - 1);
			else if ((attDice.currentResult[i]) == (defDice.currentResult[i]))
				att->set_troops(att->get_troops() - 1);
			else
				(att->set_troops(att->get_troops() - 1));
	}

	cout << "Fighting finished !" << endl << "The attacting country "<<att->get_name() <<" now has " << att->get_troops() << " armies." << endl
		 <<"The defending country "<<def->get_name()<<" now has "<<def->get_troops()<<" armies."<<endl;

	if (def->get_troops() == 0) {
		cout << "Defending country " << def->get_name() << " has no army now, it now belongs to "<<att->get_owner()->getPID()<<endl;
		def->set_owner(att->get_owner());
		this->add_territory(def);
	}

}

void Player::movingArmy() {

	for (;;) {
		cout << "Player " << player_id << " now has:" << endl;
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
		cout << "Player " << player_id << " now has:" << endl;
		for (int i = 0; i < controlled.size(); i++) {
			cout << "country: " << i + 1 << "." << controlled[i]->get_name() << ". Army:" << controlled[i]->get_troops() << endl;
		}
		break;
	}
}



int Player::get_number_controlled() {
	return this->controlled.size();
}

void Player::reinforceToWeak() {
    if (controlled.size() == 0) cout << "This player now own 0 country." << endl;
    else {
        Territory *weakest = controlled[0];
        int num = controlled[0]->get_troops();
        for (int i = 0; i < controlled.size(); i++)
            if (controlled[i]->get_troops() < num) weakest = controlled[i];
        cout << "Now performing a reinforcement........" << endl;
        weakest->set_troops((controlled.size() / 3) + weakest->get_troops());
        cout << "Reinforced " << (controlled.size() / 3) << " army to " << weakest->get_name() << endl;

        num = controlled[0]->get_troops();
        for (int i = 0; i < controlled.size(); i++)
            if (controlled[i]->get_troops() < num) weakest = controlled[i];

        vector<Territory *> ally;
        for (int i = 0; i < weakest->get_neighbors().size(); i++)
            if (weakest->get_neighbors()[i]->get_owner()->getPID().compare(player_id) == 0)
                ally.push_back(weakest->get_neighbors()[i]);
        cout << "Now performing a fortification........" << endl;
        if (ally.size() == 0) cout << weakest->get_name() << " has no ally neighbors, fortification failed." << endl;
        else {
            Territory *strongest = ally[0];
            for (int i = 0; i < ally.size(); i++)
                if (ally[i]->get_troops() > strongest->get_troops())
                    strongest = ally[i];
            if (strongest->get_troops() < 2) { cout << "ally countries has no enough army to fortify." << endl; }
            else {
                while (weakest->get_troops() < strongest->get_troops()) {
                    strongest->set_troops(strongest->get_troops() - 1);
                    weakest->set_troops(weakest->get_troops() + 1);
                }
                cout << "Fortification finished, now the player " << player_id << " has the following:" << endl;
                for (int i = 0; i < controlled.size(); i++) {
                    cout << controlled[i]->get_name() << ": " << controlled[i]->get_troops() << " troops." << endl;
                }

            }
        }
    }

}

// At start of turn, adds all new troops to strongest territory
void Player::reinforce_strongest() {
	Territory* strongest = controlled[0];
	for (Territory* t : controlled) {
		if (t->get_troops() > strongest->get_troops()) {
			strongest = t;
		}
	}
	strongest->set_troops(controlled.size() / 3 + strongest->get_troops());
	cout << strongest->get_name() << " reinforced with " << controlled.size() / 3 << " armies." << endl;
}

// Uses strongest territory to attack an unowned target until it cannot anymore
void Player::attack_with_strongest() {
	Territory* strongest = controlled[0];
	for (Territory* t : controlled) {
		if (t->get_troops() > strongest->get_troops()) {
			strongest = t;
		}
	}

	bool has_enemies;
	Territory* target;

	while (strongest->get_troops() > 1) {
		has_enemies = false;
		for (Territory* n : strongest->get_neighbors()) {
			if (n->get_owner() != this) {
				has_enemies = true;
				target = n;
				break;
			}
		}

		if (!has_enemies) {
			break;
		}

		this->fight(strongest, target);
	}
}

// Moves troops to the strongest owned territory
void Player::fortify_strongest() {
	Territory* strongest = controlled[0];
	for (Territory* t : controlled) {
		if (t->get_troops() > t->get_troops()) {
			strongest = t;
		}
	}

	Territory* strongest_neighbor;
	int strongest_neighbor_troops = 0;
	for (Territory* n : strongest->get_neighbors()) {
		if (n->get_owner() == this && n->get_troops() > strongest_neighbor_troops) {
			strongest_neighbor = n;
			strongest_neighbor_troops = n->get_troops();
		}
	}

	strongest_neighbor->set_troops(1);
	strongest->set_troops(strongest->get_troops() + strongest_neighbor_troops - 1);
	cout << strongest->get_name() << " has been fortified with " << strongest_neighbor_troops - 1 << " more armies." << endl;
}

//checking cards on hand if exchange
int Player::check_hand() {
	return this->card_on_hand->reinforcementcheck();
}


void Player::reinforceRandom() {
	if (controlled.size() == 0) cout << "This player now own 0 country, rinforcement failed" << endl;
	else {
		int num = this->controlled.size();
		num = rand() % num;
		Territory* temp = controlled[num];
		cout << "Random reniforcement. " << endl;
		temp->set_troops((controlled.size() / 3) + temp->get_troops());
		cout << "Reinforced " << (controlled.size() / 3) << " army to " << temp->get_name() << endl;
	}
}

// Random computer strategy:
void Player::attackRandom() {
	if (controlled.size() == 0) cout << "This player now own 0 country, cannot attack." << endl;
	else {
		int num = this->controlled.size();

		num = rand() % num;
		Territory* att = controlled[num];
		vector<Territory*> enemy;
		for (int i = 0; i < att->get_neighbors().size(); i++)
			if (att->get_neighbors()[i]->get_owner()->getPID() == player_id)
				enemy.push_back(att->get_neighbors()[i]);
		int flag = 0;
		do
		{

		if ((enemy.size() != 0)&&(att->get_troops()>1)) {
			Territory* def = enemy[rand() % enemy.size()];
			int attNum, defNum;
			if (att->get_troops()<=3) attNum = rand() % (att->get_troops() - 1) + 1; else attNum = rand() % 3 + 1;
			if (def->get_troops() < 2)  defNum = 1; else defNum = rand() % 2 + 1;
			cout << "------------------------------------------------" << endl;
			cout << "Random attacking :" << att->get_name() << " ->> " << def->get_name() << endl;
			Dice attDice, defDice;

			attDice.roll(attNum);
			defDice.roll(defNum);
			attDice.sortResult();
			defDice.sortResult();

			for (int i = 0; i < 3; i++) {
				if ((attDice.currentResult[i] != 0) && (defDice.currentResult[i] != 0))
					if ((attDice.currentResult[i]) > (defDice.currentResult[i])) def->set_troops(def->get_troops() - 1);
					else if ((attDice.currentResult[i]) == (defDice.currentResult[i])) att->set_troops(att->get_troops() - 1);
					else (att->set_troops(att->get_troops() - 1));
			}

			cout << "Attacking finished." << endl << "The attacting country " << att->get_name() << " now has " << att->get_troops() << " armies." << endl
				<< "The defending country " << def->get_name() << " now has " << def->get_troops() << " armies." << endl;
			cout << "------------------------------------------------" << endl;

			if (def->get_troops() == 0) { // if defender has 0 arrmy, cannot attack again, break the loop.
				cout << "Defending country " << def->get_name() << " has no army now, it now belongs to " << att->get_owner() << endl;
				def->set_owner(att->get_owner());
				this->add_territory(def);
				break;
			}
			else {
				flag = rand() % 2;   // attacking random times: if the defence country still has armies, randomly decide if attacking again.
			}
		}
		else {  // no enemy surround the chosen country, break the loop.
			flag = 1;
		}

	
		} while (flag == 0);

	}
}

void Player::fotifyRandom() {
	if (controlled.size() <= 1) cout << "This player now own 0 country, fortification failed." << endl;
	else {
		int num = this->controlled.size();
		num = rand() % num;
		Territory* temp = controlled[num];
		vector<Territory*> ally;
		for (int i = 0; i < temp->get_neighbors().size(); i++)
			if (temp->get_neighbors()[i]->get_owner()->getPID() == player_id)
				ally.push_back(temp->get_neighbors()[i]);
		if (ally.size() != 0) {
			Territory* fortifyFrom = ally[rand() % ally.size()];
			int moveNum = rand() % (fortifyFrom->get_troops() - 1) + 1;
			fortifyFrom->set_troops(fortifyFrom->get_troops() - moveNum);
			temp->set_troops(temp->get_troops() + moveNum);
			cout << "Random fortification: " << endl << "Moved " << moveNum << " armies to " << temp->get_name() << " from " << fortifyFrom->get_name() << endl;
		}
	}
}
