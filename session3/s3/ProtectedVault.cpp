#include <iostream>
#include "ProtectedVault.h"
using namespace std;

ProtectedVault::ProtectedVault():Vault(), safePassword(password), safeSecurity(security), safeMoney(money){
}

void ProtectedVault::checkWinCondition() {
    if (safeMoney == 0 && safePassword == "123" && safeSecurity == false) {
        cout << "You win!" << endl;
    } else {
        cout << "You have been arrested!" << endl;
    }
}


