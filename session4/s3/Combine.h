#ifndef COMBINE_H
#define COMBINE_H
#include "GunList.h"

class Combine{
    class DrBreen {
    private:
        int health;
        bool isAlive;
        bool hasCalledReinforcements;
        DrBreen();
        ~DrBreen();
        static DrBreen* instance;

    public:
        static DrBreen* getInstance();
        int getHealth();
        bool getIsAlive();
        bool getHasCalledReinforcements();
        void setHealth(int);
        void setReinforce(bool);
    };


private:
    int numberOfGuns;
    GunList guns;
    static int numberOfSoldiers;
    int numberOfReinforcements;
    DrBreen* drBreen;

public:
    Combine();
    Combine(int, const GunList&, int, bool);
    ~Combine();
    float calculatePower();
    DrBreen* getBreen();
};

#endif
