#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>
using namespace std;

class Weapon{
protected:
    string name;
    int id;
    //int resilience;
    int power;
    int level;
public:
    static int num;
    Weapon(string, int, int);
    ~Weapon();
    virtual string getName();
    virtual void setName(string);
    virtual int getId();
    int resilience();
    virtual int getPower();
    virtual void setPower(int);
    virtual int getLevel();
    virtual void setLevel(int);
};

class Blade : public Weapon{
    int sharpness;
    bool isMagical;
    bool isDoubled;
public:
    Blade(int, bool, bool, string, int, int);
    ~Blade();
    int getId() override;
    int getPower() override;
};


class Bow : public Weapon{
    int fireRate;
public:
    Bow(int, string, int, int);
    ~Bow();
    int getId() override;
    int getPower() override;
};

class Mace:public Weapon{
    int spikeNum;
public:
    Mace(int, string, int, int);
    ~Mace();
    int getId() override;
    int getPower() override;
};

#endif
