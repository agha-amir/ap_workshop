#ifndef GUNLIST_H
#define GUNLIST_H
#include "Gun.h"
using namespace std;
#include "string"
class Node{
public:
    Gun gun;
    Node* next;
    Node* previous;
    bool isRemoved;
    Node(const Gun&);
    ~Node();
};

class GunList{
private:
    Node * head;
    static int numberOfGuns;
public:
    GunList();
    ~GunList();

    void addGun(const Gun&);
    bool disableGun(string);
    bool recoverGun(string);
    bool completeRemoveGun(string);
    void more();
    Gun* find(string) const;
    static int gunCount();

    void printGunList();


};

#endif
