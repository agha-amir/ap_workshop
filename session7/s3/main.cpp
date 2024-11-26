#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
    Vector<Weapon*> weapons;

    weapons.push_back(new Blade(10, true, false, "Sword of Destiny", 250, 2));
    weapons.push_back(new Bow(5, "Wind Bow", 150, 1));
    weapons.push_back(new Mace(3, "Hammer of the Ancients", 180, 3));
    weapons.push_back(new Blade(7, false, true, "Ancient Blade", 400, 3));

    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "Weapon at index " << i << ":" << endl;
        weapons.printWeaponType(i);
        cout << "Power: " << weapons.getWPower(i) << endl;
        cout << "Resilience: " << weapons.getWResilience(i) << endl;
        cout << "ID: " << weapons.getWId(i) << endl;
        cout << "--------------------------" << endl;
    }

    cout << "Total Power of all weapons: " << weapons.getWTotalPower() << endl;

    weapons.sortWeapons();

    cout << "Weapons after sorting by power:" << endl;
    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "Weapon at index " << i << ":" << endl;
        weapons.printWeaponType(i);
        cout << "Power: " << weapons.getWPower(i) << endl;
        cout << "Resilience: " << weapons.getWResilience(i) << endl;
        cout << "ID: " << weapons.getWId(i) << endl;
        cout << "--------------------------" << endl;
    }

    cout << "Popping back the last weapon..." << endl;
    weapons.pop_back();

    cout << "Weapons after popping back:" << endl;
    for (int i = 0; i < weapons.Size(); ++i) {
        cout << "Weapon at index " << i << ":" << endl;
        weapons.printWeaponType(i);
        cout << "Power: " << weapons.getWPower(i) << endl;
        cout << "Resilience: " << weapons.getWResilience(i) << endl;
        cout << "ID: " << weapons.getWId(i) << endl;
        cout << "--------------------------" << endl;
    }

    // پاک کردن تمام سلاح‌ها
    weapons.clear();
    cout << "After clearing the vector:" << endl;
    cout << "Size: " << weapons.Size() << endl;

    // حذف سلاح‌ها (در واقع باید داینامیک‌های مربوط به سلاح‌ها را آزاد کنیم)
    for (int i = 0; i < weapons.Size(); ++i) {
        delete weapons[i];
    }

    return 0;
}
