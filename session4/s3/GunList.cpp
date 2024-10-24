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

float GunList::totalAmmoFireRate() {
    float total = 0;
    Node* current = head;
    do {
        if(!current->isRemoved){
            total += current->gun.getAmmo() * current->gun.getFireRate();

            current = current->next;
        }
    } while (current != head);
    return total;
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

