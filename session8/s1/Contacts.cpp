#include "Contacts.h"


Contact::Contact(string n, string fk, string fv) {
    this->name = n;
    this->phoneNums.insert(make_pair(fk, fv));
}

Contact::~Contact() {}

void Contact::addNum(string key, string val) {
    phoneNums[key] = val;
}

void Contact::deleteNum(string key) {
    if(phoneNums.find(key) == phoneNums.end()){
        cout<<"this number type doesn't exist"<<endl;
        return;
    }
    phoneNums.erase(key);
}

void Contact::editNum(string key, string val) {
    if(phoneNums.find(key) == phoneNums.end()){
        cout<<"this number type doesn't exist"<<endl;
        return;
    }

    phoneNums[key] = val;
}

void Contact::displayNum() {
    for (auto i : phoneNums){
        cout<<"type:\t"<<i.first<<"\nnumber:\t"<<i.second<<endl;
    }
}

Contacts::Contacts() {}
Contacts::~Contacts() {}

void Contacts::addContact(string n, string fk, string fv) {
    Contact cnt(n, fk, fv);
    contacts[n] = cnt;
    if(contacts.find(n) == contacts.end()){cout<<"err"<<endl;}
}

void Contacts::deleteContact(string n) {
    if(contacts.find(n) == contacts.end()){
        cout<<"this contact doesn't exist"<<endl;
        return;
    }
    contacts.erase(n);
}

void Contacts::editContact(string n, string newN) {
    if(contacts.find(n) == contacts.end()){
        cout<<"this contact doesn't exist"<<endl;
        return;
    }

    contacts[newN] = contacts[n];
    contacts.erase(n);
}

Contact::Contact() {}

void Contacts::addContactPH(string n, string t, string p) {
    if(contacts.find(n) == contacts.end()){
        cout<<"the contact doesn't exist"<<endl;
        return;
    }
    contacts[n].addNum(t, p);
}

void Contacts::editContactPH(string n, string t, string p) {
    if(contacts.find(n) == contacts.end()){
        cout<<"the contact doesn't exist"<<endl;
        return;
    }
    contacts[n].editNum(t, p);
}

void Contacts::deleteContactPH(string n, string t){
    if(contacts.find(n) == contacts.end()){
        cout<<"the contact doesn't exist"<<endl;
        return;
    }
    contacts[n].deleteNum(t);
}

void Contacts::addFav(string n) {
    if(contacts.find(n) == contacts.end()){
        cout<<"the contact doesn't exist"<<endl;
        return;
    }

    favs.push_back(n);
}

void Contacts::displayFav() {
    for(auto i : favs){
        cout<<i<<endl;
    }
}

void Contacts::remFav(string n) {
    auto removed = remove(favs.begin(), favs.end(), n);
    favs.erase(removed, favs.end());
}

void Contacts::displayContact(string n) {
    if(contacts.find(n) == contacts.end()){
        cout<<"the contact doesn't exist"<<endl;
        return;
    }
    contacts[n].displayNum();
}

void Contacts::searchContact(string str) {
    for (auto i : contacts) {
        if(i.first.find(str) == 0){
            cout<<i.first<<endl;
        }
    }
}

