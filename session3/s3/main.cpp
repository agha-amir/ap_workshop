#include <iostream>
#include "Vault.h"
#include "ProtectedVault.h"
#include <cstring>
#include <cstddef>
using namespace std;
int main() {
    Vault newVault;
    ProtectedVault newProtectedVault;
    string *newVaultPasswordPtr = (string * ) & newVault;
    bool *newVaultSecurityPtr = (bool *) (newVaultPasswordPtr + 1);
    int *newVaultMoneyPtr = (int *) (newVaultSecurityPtr + 1);
    *newVaultPasswordPtr = "123";
    *newVaultSecurityPtr = false;
    *newVaultMoneyPtr = 0;
    newVault.checkWinCondition();
    string *newProtectedVaultPasswordPtr = (string * ) & newProtectedVault;
    bool *newProtectedVaultSecurityPtr = (bool *) (newProtectedVaultPasswordPtr + 1);
    int *newProtectedVaultMoneyPtr = (int *) (newProtectedVaultSecurityPtr + 1);

    *newProtectedVaultPasswordPtr = "123";
    *newProtectedVaultSecurityPtr = false;
    *newProtectedVaultMoneyPtr = 0;
    newProtectedVault.checkWinCondition();

    string *castedPassword = const_cast<string*>(newProtectedVaultPasswordPtr);
    bool *castedSec = const_cast<bool*>(newProtectedVaultSecurityPtr);
    int *castedMoney = const_cast<int*>(newProtectedVaultMoneyPtr);

    *castedPassword = "123";
    *castedMoney = 0;
    *castedSec = false;

    newProtectedVault.checkWinCondition();

    return 0;
}


