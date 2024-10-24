#include "Combine.h"

int Combine::numberOfSoldiers = 30;

Combine::DrBreen* Combine::DrBreen::instance = nullptr;

Combine::DrBreen* Combine::DrBreen::getInstance() {
    if (instance == nullptr) {
        instance = new DrBreen();
    }
    return instance;
}

Combine::DrBreen::DrBreen() {}

Combine::DrBreen::~DrBreen() {}

void Combine::DrBreen::setHealth(int h) {
    this->health = h;
}

void Combine::DrBreen::setReinforce(bool r) {
    this->hasCalledReinforcements = r;
}

int Combine::DrBreen::getHealth() {
    return this->health;
}

Combine::Combine():numberOfGuns(0), numberOfReinforcements(0){
    this->drBreen = DrBreen::getInstance();
}

Combine::Combine(int ReinforceNo, const GunList & gl, int breenHealth, bool breenReinforce): numberOfReinforcements(ReinforceNo), guns(gl), numberOfGuns(gl.gunCount()){
    drBreen = DrBreen::getInstance();
    drBreen->setHealth(breenHealth);
    drBreen->setReinforce(breenReinforce);
}

Combine::~Combine() {}

float Combine::calculatePower() {
    float totalAF = guns.totalAmmoFireRate();
    int SoldierAndReinforce = 0;
    if(drBreen->getHasCalledReinforcements()){
        SoldierAndReinforce = this->numberOfReinforcements + numberOfSoldiers;
    }
    else{
        SoldierAndReinforce = this->numberOfSoldiers;
    }
    totalAF *= SoldierAndReinforce;
    return totalAF;
}

bool Combine::DrBreen::getHasCalledReinforcements() {
    return hasCalledReinforcements;
}


Combine::DrBreen *Combine::getBreen() {
    return this->drBreen;
}