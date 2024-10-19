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
    static int numberOfGuns;

public:
    Gun();
    Gun(int, string, float, bool);

    Gun& operator+(const Gun&);
    Gun& operator+=(const Gun&);
    bool operator==(const Gun&) const;
    bool operator!=(const Gun&) const;
    Gun& operator=(const Gun&);
    Gun operator--(int); 
    Gun& operator--(); 
    Gun operator++(int);
    Gun& operator++(); 
    Gun& operator[](int);
    Gun& operator*(int);
    Gun& operator/(int);
    Gun& operator*=(int);
    Gun& operator/=(int);
    friend istream& operator>>(istream&, Gun&);
    friend ostream& operator<<(ostream&, const Gun&);

    static int getNumberOfGuns();
};

#endif //