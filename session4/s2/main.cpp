#include "GunList.h"
#include "Gun.h"

void menu(GunList* gunList) {
    int choice;
    do {
        cout << "menu: "<<endl;
        cout << "1.add a new gun"<<endl;
        cout << "2.disable a gun"<<endl;
        cout << "3.recover a disabled gun"<<endl;
        cout << "4.completely remove a gun"<<endl;
        cout << "5.more(==, ++, --, /=, *=)"<<endl;
        cout << "6.print the list"<<endl;
        cout << "press 0 to exit"<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                Gun newGun;
                cin >> newGun;
                gunList->addGun(newGun);
                break;
            }
            case 2: {
                string name;
                cout << "enter the gun's name to disable: ";
                cin >> name;
                gunList->disableGun(name);
                break;
            }
            case 3: {
                string name;
                cout << "enter gun name to recover(enable): ";
                cin >> name;
                gunList->recoverGun(name);
                break;
            }
            case 4: {
                string name;
                cout << "enter gun name to completely delete: ";
                cin >> name;
                gunList->completeRemoveGun(name);
                break;
            }
            case 5: {
                gunList->more();
                break;
            }
            case 6:{
                gunList->printGunList();
                break;
            }
        }
    } while (choice != 0);
}

int main(){
    GunList* gunList = new GunList();
    menu(gunList);

    delete gunList;
    return 0;
}