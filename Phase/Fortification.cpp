#include "Fortification.h"
#include "../Player/Player.h"

using namespace std;

Fortification::Fortification() {

}

Fortification::Fortification(Player &P) {
    ptemp = & P;
}

void Fortification::fortificate() {
    bool t = true;
    do {
        cout << "Please select the territory number you want to take troops from :" << endl;
		std::vector<Territory*> controlled = ptemp->get_own_territories();
        //Territory * controlled = ptemp->get_controlled();
        for (int i = 0; i < this->ptemp->get_number_controlled(); i++) {
            cout << i << ". " << (*controlled[i]).get_name() << " with " << (*controlled[i]).get_troops() << "  troops." << endl;
        }
        int in;
        cin >> in;
        if (in >= 0 && in < this->ptemp->get_number_controlled()) {
            t = fortificate1(&(*controlled[in]));

        }
        else
            cout << "invalid input." << endl
                 << "------------------------------------------" << endl;
    } while (t);
}

bool Fortification::fortificate1(Territory* take) {

    cout << "the Territory " << take->get_name() << " has " << take->get_troops() << " troops" << endl
         << "Please enter the number of troops to take from this territory" << endl;
    int re;
    cin >> re;
    if (re > 0 && re < take->get_troops()) {
        return fortificate2(take, re);

    }
    else {
        cout << "invalid input" << endl;
        return true;
    }
}

bool Fortification::fortificate2(Territory*take, int re) {
    int num_nei = take->get_neighbors().size();
    cout << "Please select the territories to send troops" << endl;
    vector<Territory*> neighbour;
    int k = 0;
    for (int i = 0; i < num_nei; i++) {
        for (int j = 0; j < ptemp->get_number_controlled(); j++) {
            if ((take->get_neighbors()[i])->equals(ptemp->get_own_territories()[j])) {
                cout << k << ". " << (ptemp->get_own_territories()[j])->get_name() << " currently has " << (ptemp->get_own_territories()[j])->get_troops() << " troops" << endl;
                neighbour.push_back((ptemp->get_own_territories()[j]));
                k++;
            }

        }


    }
    if (k == 0) {
        cout << "this Territory has no neighbour territories controlled by player" << endl;
        return false;
    }

    int in;
    cin >> in;
    if (in > -1 && in < k) {
        neighbour[in]->set_troops(neighbour[in]->get_troops()+re);
        take->set_troops(take->get_troops() - re);
        cout << "fortification succeed" << endl;
        return false;
    }
    else {
        cout << "invalid input " << endl;
        return true;
    }




    return true;
}
