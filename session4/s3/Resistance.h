#ifndef RESISTANCE_H
#define RESISTANCE_H

#include "GunList.h"

class Resistance {
    class GordonFreeman {
    private:
        int health;
        int armor;
        bool isAlive;
        GordonFreeman();
        ~GordonFreeman();
        static GordonFreeman* instance;

    public:
        static GordonFreeman* getInstance();
        int getHealthArmor();
        bool getIsAlive();
        void setHealth(int);
        void setArmor(int);
    };

private:
    int numberOfGuns;
    GunList guns;
    static int numberOfWarriors;
    int numberOfMedKits;
    GordonFreeman* gordonFreeman;

public:
    Resistance();
    Resistance(int, const GunList&, int, int);
    ~Resistance();
    float calculatePower();

    GordonFreeman* getGordon();
};

#endif
