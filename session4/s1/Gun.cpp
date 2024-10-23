#include "Gun.h"

int Gun::numberOfGuns = 0;

Gun::Gun() : ammo(0), name(""), fireRate(0.0f), isAutomatic(false) {
    numberOfGuns++;
}

Gun::Gun(int ammo, string name, float fireRate, bool isAutomatic): ammo(ammo), name(name), fireRate(fireRate), isAutomatic(isAutomatic) {
    numberOfGuns++;
}

const Gun& Gun::operator+(const Gun& g){
    Gun result;
    ammo += g.ammo;
    name += g.name;
    fireRate *= g.fireRate;
    isAutomatic |= g.isAutomatic;
    return *this;
}

const Gun& Gun::operator+=(const Gun& g) {
    *this = *this + g;
    return *this;
}

bool Gun::operator==(const Gun& g) const {
    return (ammo == g.ammo && name == g.name && fireRate == g.fireRate && isAutomatic == g.isAutomatic);
}

bool Gun::operator!=(const Gun& g) const {
    return !(*this == g);
}

const Gun& Gun::operator=(const Gun& g) {

    ammo = g.ammo;
    name = g.name;
    fireRate = g.fireRate;
    isAutomatic = g.isAutomatic;

    return *this;
}

const Gun& Gun::operator--(int) {
    ammo--;
    return *this;
}

const Gun& Gun::operator--() {
    ammo--;
    return *this;
}

const Gun& Gun::operator++(int) {
    ammo++;
    return *this;
}

const Gun& Gun::operator++() {
    ammo++;
    return *this;
}

const Gun& Gun::operator[](int newAmmo) {
    ammo = newAmmo;
    return *this;
}

const Gun& Gun::operator*(int coef) {
    ammo *= coef;
    return *this;
}

const Gun& Gun::operator/(int coef) {
    if (coef == 0) {
        throw runtime_error("division by zero");
    }
    ammo /= coef;
    return *this;
}

const Gun& Gun::operator*=(int coef) {
    ammo *= coef;
    return *this;
}

const Gun& Gun::operator/=(int coef) {
    if (coef == 0) {
        throw runtime_error("division by zero");
    }
    ammo /= coef;
    return *this;
}

istream& operator>>(istream& in, Gun& g) {
    cout << "enter the gun's ammo: ";
    in >> g.ammo;
    cout << "enter the gun's name: ";
    in >> g.name;
    cout << "enter the gun's fire rate: ";
    in >> g.fireRate;
    cout << "is the gun automatic (1 for yes, 0 for no)? ";
    in >> g.isAutomatic;
    return in;
}

ostream& operator<<(ostream& out, const Gun& g) {
    out << "ammo: " << g.ammo << endl;
    out << "name: " << g.name << endl;
    out << "fire Rate: " << g.fireRate << endl;
    out << "is automatic: " << boolalpha << g.isAutomatic << endl;
    return out;
}

int Gun::getNumberOfGuns() {
    return numberOfGuns;
}
