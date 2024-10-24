#include "War.h"

War::War():res(), cmb() {}

War::War(Resistance &resistance, Combine &combine):res(resistance), cmb(combine) {

}

War::~War() {}

void War::startWar() {
    float resistancePower = res.calculatePower();
    cout << "resistance's power:   " << resistancePower << endl;
    float combinePower = cmb.calculatePower();
    cout << "combine's power:  " << combinePower << endl;
    cout << "breen's health:  " << cmb.getBreen()->getHealth() << endl;
    cout << "gordon's health+armor:  " << res.getGordon()->getHealthArmor() << endl;
    if(resistancePower > combinePower){
        if((resistancePower - combinePower) > cmb.getBreen()->getHealth()){
            this->result = 0;
            return;
        }
        else{
            this->result = 2;
            return;
        }
    }

    else{
        if((combinePower - resistancePower) > res.getGordon()->getHealthArmor()){
            this->result = 1;
            return;
        }
        else{
            this->result = 2;
            return;
        }
    }
}

int War::getResult() {
    return this->result;
}

