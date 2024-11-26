#include "Weapon.h"

int Weapon::num = 0;
Weapon::Weapon(string n, int p, int l):name(n), power(p), level(l){
    num++;
    this->id = num;
}

Weapon::~Weapon() {}

int Weapon::resilience() {
    return power / 10;
}

int Weapon::getId() {return id;}

string Weapon::getName() {return name;}

int Weapon::getLevel() {return level;}

int Weapon::getPower() {return power;}

void Weapon::setName(string n) { this->name = n;}

void Weapon::setLevel(int l) { this->level = l;}

void Weapon::setPower(int p) { this->power = p;}

Blade::Blade(int s, bool ism, bool isd, string n, int p, int l): Weapon(n, p, l), sharpness(s), isMagical(ism), isDoubled(isd) {}

Blade::~Blade() {}

int Blade::getId() {return 10000+ this->id;}

int Blade::getPower() {
    int p = this->power * this->sharpness;
    int d = isDoubled * 2;
    int m = isMagical * 3;
    if(power < 100){ this->level = 0;}
    else if(power >= 100 and power <= 200){ this->level = 1;}
    else if(power > 200 and power <= 300){this->level = 2;}
    else if(power > 300 and power <= 400){this->level = 3;}
    if(m){
        if(d){return p*m*d;}
        return p*m;
    }
    return p;
}

Bow::Bow(int fr, string n, int p, int l):Weapon(n, p, l), fireRate(fr) {}
Bow::~Bow() {}

int Bow::getId() {
    return 20000+ this->id;
}
int Bow::getPower() {return this->power * this->fireRate;}

Mace::Mace(int sn, string n, int p, int l): Weapon(n, p, l), spikeNum(sn){}
Mace::~Mace() {}

int Mace::getId() {return 30000 + this->id;}

int Mace::getPower() {return this->spikeNum * this->power;}
