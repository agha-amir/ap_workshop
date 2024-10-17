#include "Vault.h"
#include <string>

#ifndef PROTECTEDVAULT_H
#define PROTECTEDVAULT_H

class ProtectedVault : public Vault{
protected:
    const string safePassword;
    const bool safeSecurity;
    const int safeMoney;

public:
    ProtectedVault();
    void print();
    void checkWinCondition();
};

#endif
