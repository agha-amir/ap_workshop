#ifndef SESSION4_GUN_H
#define SESSION4_GUN_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Gun {
private:
    int ammo;
    string name;
    float fireRate;
    bool isAutomatic;

public:
    Gun();
    Gun(int, string, float, bool);

    const Gun& operator+(const Gun&);
    const Gun& operator+=(const Gun&);
    bool operator==(const Gun&) const;
    bool operator!=(const Gun&) const;
    const Gun& operator=(const Gun&);
    const Gun& operator--(int);
    const Gun& operator--();
    const Gun& operator++(int);
    const Gun& operator++();
    const Gun& operator[](int);
    const Gun& operator*(int);
    const Gun& operator/(int);
    const Gun& operator*=(int);
    const Gun& operator/=(int);
    friend istream& operator>>(istream&, Gun&);
    friend ostream& operator<<(ostream&, const Gun&);
    bool operator>(int) const;
    bool operator<(int) const;
    bool operator<=(int) const;
    bool operator>=(int) const;
    Gun& operator<<(int);
    Gun& operator>>(int);
    string getName()const;
    static int getNumberOfGuns();
    int getAmmo();
    float getFireRate();
};

#endif