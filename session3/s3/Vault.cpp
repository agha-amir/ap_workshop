#include <iostream>
#include "Vault.h"
using namespace std;

Vault::Vault() {
    password = "hNcaal9*930okf";
    security = true;
    money = 100;
}

int Vault::getMoney() {
    cout << "You lose!" << endl;
    return money;
}

void Vault::setMoney(int newValue) {
    cout << "You lose!" << endl;
    money = newValue;
}

void Vault::checkWinCondition() {
    if (money == 0 && password == "123" && security == false) {
        cout << "You win!" << endl;
    } else {
        cout << "You have been arrested!" << endl;
    }
}

