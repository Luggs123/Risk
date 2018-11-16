
#include <iostream>
#include "../Player/Player.h"
#include "Benevolent.h"

using namespace std;

void Benevolent::execute(Player* p) {
    cout << "Benevolent strategy executed."<<endl;
    cout << "Player " << p->getPID() << " now own the following:" << endl;
    p->show_territory();
    cout << endl;
    p->reinforceToWeak();

}