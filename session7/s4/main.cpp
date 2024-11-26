#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
    Vector<Weapon*> weapons;

    weapons.push_back(new Blade(10, true, false, "Sword of Destiny", 250, 2));
    weapons.push_back(new Bow(5, "Wind Bow", 150, 1));
    weapons.push_back(new Mace(3, "Hammer of the Ancients", 180, 3));
    weapons.push_back(new Blade(7, false, true, "Ancient Blade", 400, 3));

    for (auto &i : weapons) {
        cout<<i->getPower()<<endl;
    }
    return 0;
}
