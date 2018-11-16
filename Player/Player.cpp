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

void Player::set_free_troops(int num) { this->free_troops = num; }
int Player::get_free_troops() { return this->free_troops; }

void Player::showcardsonHand() { this->card_on_hand->display_cards(); }

void Player::add_territory(Territory* x) { this->controlled.push_back(x); }
//void Player::lose_territory(Territory &x){}
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
	cout << "This is the reinforce method" << endl;
	if (this->reinforcement == nullptr)
		this->reinforcement = new Reinforcement(*this);

	this->reinforcement->run_reinforcement();
}

void Player::attack() {
	Territory* att;
	Territory* def;

	cout << "choose your countries to attack from." << endl;
	this->show_territory(); cout << endl;
	int choice;
	cin >> choice;
	if ((choice >= 1) && (choice <= controlled.size())) {
		att = controlled[choice - 1];
		if (att->get_troops() < 2) { cout << "This country has less than 2 armies. Back to main menu."; }
		else
		{
			cout << "choose a neighbor to attack: ";
			vector<Territory*> temp;
			temp = att->get_neighbors();
			vector<Territory*> neighbors;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i]->get_owner()->getPID().compare(player_id) != 0) {
					neighbors.push_back(temp[i]);
				}
			}
			for (int i=0;i<neighbors.size();i++) cout << (i + 1) << ". " << neighbors[i]->get_name() << " ";
			int num;
			cin >> num;
			num--;
			if ((num > (neighbors.size() - 1)) || (num < 0)) cout << "invalid index.";
			else {
				def = neighbors[num];
				this->fight(att, def);
			}
		}
	}

}

void Player::fortify() {
	cout << "This is the fortify method" << endl;

	if (this->fortification == nullptr)
		this->fortification = new Fortification(*this);

	this->fortification->fortificate();
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
	int attNum = -1;
	int	defNum = -1;
	for (;;) {
		cout << "choice number of dice to roll (attacker), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
		int tp=att->get_troops() - 1;
		if (tp >= temp)
			if ((temp >= 1) && (temp <= 3)) { attNum = temp; break; }

	}
	for (;;) {
		cout << "choice number of dice to roll (defender), repeat if the number is invalid" << endl;
		int temp;
		cin >> temp; cout << endl;
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

Territory* Player::get_controlled() {
	return controlled[0];
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
