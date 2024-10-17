#ifndef VAULT_H
#define VAULT_H

#include <string>
using namespace std;

class Vault {
protected:
    string password;
    bool security;
    int money;

public:
    Vault();
    int getMoney();
    void setMoney(int newValue);
    void checkWinCondition();
};

#endif