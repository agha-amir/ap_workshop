#include "GunList.h"
using namespace std;
#include "string"
int GunList::numberOfGuns = 0;
Node::Node(const Gun & g): gun(g), next(nullptr), previous(nullptr), isRemoved(false){
}

Node::~Node(){

}

GunList::GunList() : head(nullptr){}
GunList::~GunList() {
    if(head == nullptr){
        return;
    }
    Node* current = head;
    do {
        Node* temp = current->next;
        delete current;
        current = temp;
    } while (current != head);
}

void GunList::addGun(const Gun &g) {
    Node* newNode = new Node(g);
    if(head == nullptr){
        head = newNode;
        head->previous = head;
        head->next = head;
        numberOfGuns ++;
    }
    else{
        head->previous->next = newNode;
        newNode->previous = head->previous;
        newNode->next = head;
        head->previous = newNode;
        numberOfGuns ++;
    }
}


bool GunList::disableGun(string Name) {
    Node* current = head;

    do{
        if(current->gun.getName() == Name){
            current->isRemoved = true;
            return true;
            numberOfGuns --;
        }
        current = current->next;
    } while (current != head);

    cout<<"gun not found or is already disabled"<<endl;
    return false;
}

bool GunList::recoverGun(string Name) {
    Node* current = head;

    do{
        if(current->gun.getName() == Name){
            current->isRemoved = false;
            numberOfGuns++;
            return true;
        }
        current = current->next;
    } while (current != head);

    cout<<"gun not found or wasn't disabled"<<endl;
    return false;
}

bool GunList::completeRemoveGun(string Name) {
    Node* current = head;
    if(current->next == current){
        delete head;
        head = nullptr;
        numberOfGuns--;
        return true;
    }

    do{
        if(current->gun.getName() == Name){
            current->isRemoved = true;
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
            current = nullptr;
            numberOfGuns--;
            return true;
        }
        current = current->next;
    } while (current != head);

    cout<<"gun not found"<<endl;
    return false;
}

Gun* GunList::find(string Name) const {
    Node* current = head;
    do {
        if(current->gun.getName() == Name){return &current->gun;}
        current = current->next;
    } while (current != head);
    return nullptr;
}

int GunList::gunCount() {
    return numberOfGuns;
}

void GunList::more() {
    if (!head) {
        cout << "the list is empty"<<endl<<endl;
        return;
    }

    int choice;
    do {
        cout <<endl<<endl<< "more:"<<endl;
        cout << "1.increment ammo of a gun"<<endl;
        cout << "2.decrement ammo of a gun"<<endl;
        cout << "3.compare two guns"<<endl;
        cout << "4.multiply ammo of a gun by an int"<<endl;
        cout << "5.divide ammo of a gun by an int"<<endl;
        cout << "6.check if the guns ammo is < your desired number"<<endl;
        cout << "7.check if the guns ammo is > your desired number"<<endl;
        cout << "8.check if the guns ammo is <= your desired number"<<endl;
        cout << "9.check if the guns ammo is >= your desired number"<<endl;
        cout << "10.do a right shift on gun's ammo number(>>)"<<endl;
        cout << "11.do a left shift on gun's ammo number(<<)"<<endl;
        cout << "0.exit"<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                string Name;
                cout<<"enter gun's name: ";
                cin>>Name;
                Gun* gun = find(Name);
                if(gun!= nullptr){
                    (*gun)++;
                    cout<<"updated gun: "<<endl<<*gun;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }
            case 2: {
                string Name;
                cout<<"enter gun's name: ";
                cin>>Name;
                Gun* gun = find(Name);
                if(gun!= nullptr){
                    (*gun)--;
                    cout<<"updated gun: "<<endl<<*gun;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }
            case 3: {
                string gunName1, gunName2;
                cout << "enter the name of the first gun: ";
                cin >> gunName1;
                cout <<endl<< "enter the name of the second gun: ";
                cin >> gunName2;
                Gun* gun1 = find(gunName1);
                Gun* gun2 = find(gunName2);
                if (gun1 && gun2) {
                    if (*gun1 == *gun2) {
                        cout << "the two guns are equal"<<endl;
                    } else {
                        cout << "the two guns are not equal"<<endl;
                    }
                } else {
                    cout << "one or both guns not found"<<endl;
                }
                break;
            }
            case 4: {
                string Name;
                int coef;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);
                if (gun) {
                    cout<<endl<<"enter the coefficient: ";
                    cin >>coef;
                    *gun *= coef;
                    cout<<"updated gun"<<*gun;
                } else {
                    cout << "gun not found."<<endl;
                }
                break;
            }
            case 5: {
                string Name;
                int coef;
                cout << "enter the gun's name: ";
                cin >> Name;

                try {
                    Gun* gun = find(Name);
                    if (gun != nullptr) {
                        cout<<endl<<"enter the coefficient: ";
                        cin >>coef;
                        *gun /= coef;
                        cout<<"updated gun"<<*gun;
                    } else {
                        cout << "gun not found"<<endl;
                    }
                } catch (const runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 6:{
                string Name;
                int ammoNum;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);
                if(gun != nullptr){
                    cout<<endl<<"enter the number: ";
                    cin >>ammoNum;
                    bool compared = *gun < ammoNum;
                    cout<<"is the gun's ammo smaller than your number: "<<boolalpha<<compared <<endl;}
                else{cout<<"gun not found"<<endl;}
                break;
            }

            case 7:{
                string Name;
                int ammoNum;
                cout << "enter the gun's name: ";
                cin >> Name;

                Gun* gun = find(Name);
                if(gun != nullptr){
                    cout<<endl<<"enter the number: ";
                    cin >>ammoNum;
                    bool compared = *gun> ammoNum;
                    cout<<"is the gun's ammo grater than your number: "<<boolalpha<< compared <<endl;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }
            case 8:{
                string Name;
                int ammoNum;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);

                if(gun != nullptr){
                    cout<<endl<<"enter the number: ";
                    cin >>ammoNum;
                    bool compared = *gun <= ammoNum;
                    cout<<"is the gun's ammo <= your number: "<<compared <<endl;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }

            case 9:{
                string Name;
                int ammoNum;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);
                if(gun != nullptr){
                    cout<<endl<<"enter the number: ";
                    cin >>ammoNum;
                    bool compared = *gun >= ammoNum;
                    cout<<"is the gun's ammo >= your number: "<<boolalpha<<compared <<endl;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }

            case 10:{
                string Name;
                int numBits;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);
                if(gun != nullptr){
                    cout<<endl<<"enter the number of bits: ";
                    cin >>numBits;
                    *gun >> numBits;
                    cout<<"updated gun: "<<endl<<*gun;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }

            case 11:{
                string Name;
                int numBits;
                cout << "enter the gun's name: ";
                cin >> Name;
                Gun* gun = find(Name);
                if(gun != nullptr){
                    cout<<endl<<"enter the number of bits: ";
                    cin >>numBits;
                    *gun << numBits;
                    cout<<"updated gun: "<<endl<<*gun;
                }
                else{cout<<"gun not found"<<endl;}
                break;
            }
        }
    }while (choice != 0);
}

void GunList::printGunList() {

    Node* current = head;
    cout<<endl<<endl;

    do {
        if(head == nullptr){
            cout<<"the list is empty"<<endl;
            continue;
        }
        cout<<current->gun;
        cout<<"-----------------"<<endl;
        current = current->next;
    } while (current != head);
}

