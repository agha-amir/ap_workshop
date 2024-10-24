#include "Resistance.h"

int Resistance::numberOfWarriors = 30;
Resistance::GordonFreeman* Resistance::GordonFreeman::instance = nullptr;

Resistance::GordonFreeman* Resistance::GordonFreeman::getInstance() {
    if (instance == nullptr) {
        instance = new GordonFreeman();
    }
    return instance;
}


Resistance::GordonFreeman::GordonFreeman() {}
Resistance::GordonFreeman::~GordonFreeman() {}

void Resistance::GordonFreeman::setHealth(int h) {
    this->health = h;
}

void Resistance::GordonFreeman::setArmor(int a) {
    this->armor = a;
}

int Resistance::GordonFreeman::getHealthArmor() {
    return this->health + this->armor;
}

Resistance::Resistance():numberOfMedKits(0), numberOfGuns(0) {
    this->gordonFreeman = GordonFreeman::getInstance();
}

Resistance::Resistance(int medKitNo, const GunList& gl, int gordonHealth, int gordonArmor):numberOfMedKits(medKitNo), guns(gl), numberOfGuns(gl.gunCount()){
    this->gordonFreeman = GordonFreeman::getInstance();
    this->gordonFreeman->setHealth(gordonHealth);
    this->gordonFreeman->setArmor(gordonArmor);
}

Resistance::~Resistance() {}

float Resistance::calculatePower(){
    float totalAF = guns.totalAmmoFireRate();
    totalAF *= numberOfWarriors;
    totalAF += (10 * this->numberOfMedKits);
    return totalAF;
}

Resistance::GordonFreeman *Resistance::getGordon() {
    return this->gordonFreeman;
}