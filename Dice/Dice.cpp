#include "Dice.h"

using namespace std;

Dice::Dice()
{

    name = "Anonymous player";
    totalRolled = 0;
    diceStats[1] = 0;
    diceStats[2] = 0;
    diceStats[3] = 0;
    diceStats[4] = 0;
    diceStats[5] = 0;
    diceStats[6] = 0;
    currentResult[0] = 0;
    currentResult[1] = 0;
    currentResult[2] = 0;
}

Dice::Dice(string nam) {
    name = nam;
    totalRolled = 0;
    diceStats[1] = 0;
    diceStats[2] = 0;
    diceStats[3] = 0;
    diceStats[4] = 0;
    diceStats[5] = 0;
    diceStats[6] = 0;
    currentResult[0] = 0;
    currentResult[1] = 0;
    currentResult[2] = 0;
};

void Dice::getPercentage() {
    cout << fixed << setprecision(2);
    cout << "Percentage for " << name << ":" << endl;
    for (int i = 1; i <= 6; i++) {
        double temp = ((double)diceStats[i] / (double)totalRolled) * 100;
        cout << i << ": " << temp << "%" << endl;
    }

};
void Dice::roll(int num)
{

    for (int i = 0; i < 3; i++) currentResult[i] = 0;
    currentRolled = num;
    cout << "result:" << endl;
    for (int i = 0; i < num; i++) {
        int temp = (rand() % 6) + 1;
        cout << temp << " ";
        currentResult[i] = temp;
        diceStats[temp] += 1;
    }
    cout << endl;
};
void Dice::game() {
    cout << "Hello player " << name << ", how many dice you want to roll ? (from 1 to 3)" << endl;
    int numOfdice;
    cin >> numOfdice; cout << endl;
    if ((numOfdice >= 1) && (numOfdice <= 3))
    {
        totalRolled += numOfdice;
        roll(numOfdice);
        getPercentage();
    }
    else cerr << "invalid number of dice entered, back to main menu.\n"; cout << endl;

}

void Dice::sortResult() {
    for (int i=0;i<currentRolled;i++)
        for (int j = i + 1; j < currentRolled; j++)
            if (currentResult[j] > currentResult[i]) {
                int temp = currentResult[i];
                currentResult[i] = currentResult[j];
                currentResult[j] = temp;
            }
    cout << "sorted armies: ";
    for (int i = 0; i < currentRolled; i++) cout << currentResult[i]<<" ";
    cout << endl;
}