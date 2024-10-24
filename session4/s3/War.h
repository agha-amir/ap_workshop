#ifndef WAR_H
#define WAR_H

#include "Resistance.h"
#include "Combine.h"

class War{
private:
    Resistance res;
    Combine cmb;
    int result;
public:
    War();
    War(Resistance& resistance, Combine& combine);
    ~War();
    void startWar();
    int getResult();
};


#endif
