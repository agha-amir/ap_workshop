#include <iostream>
#include "Vector.cpp"
using namespace amir;
using namespace std;

int main() {
    amir::Vector<Weapon*> weapons;

    weapons.push_back(new Blade(10, true, false, "Sword of Destiny", 250, 2));
    weapons.push_back(new Bow(5, "Wind Bow", 150, 1));
    weapons.push_back(new Mace(3, "Hammer of the Ancients", 180, 3));
    weapons.push_back(new Blade(7, false, true, "Ancient Blade", 400, 3));

    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "index " << i <<":"<<endl;
        weapons.printWeaponType(i);
        cout << "power: " << weapons.getWPower(i)<<endl;
        cout << "resilience: " << weapons.getWResilience(i)<<endl;
        cout << "id: " << weapons.getWId(i)<<endl;
        cout << "---------------------" << endl<<endl;
    }

    cout << "total power of all weapons: " << weapons.getWTotalPower() << endl;

    weapons.sortWeapons();

    cout << "weapons after sorting by power:" << endl;
    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "index " << i << ":" << endl;
        weapons.printWeaponType(i);
        cout << "power: " << weapons.getWPower(i) << endl;
        cout << "resilience: " << weapons.getWResilience(i) << endl;
        cout << "id: " << weapons.getWId(i) << endl;
        cout << "---------------------" << endl;
    }

    cout << "Popping back the last weapon..." << endl;
    weapons.pop_back();

    cout << "weapons after popping back:" << endl;
    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "index " << i << ":" << endl;
        weapons.printWeaponType(i);
        cout << "power: "<<weapons.getWPower(i) << endl;
        cout << "resilience: "<<weapons.getWResilience(i)<<endl;
        cout<<"id: "<<weapons.getWId(i)<<endl;
        cout<<"---------------------"<<endl<<endl;
    }

    weapons.clear();
    cout<<"after clearing the vector:"<<endl;
    cout<<"size: "<<weapons.Size()<< endl;

    return 0;
}
