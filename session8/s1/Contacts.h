#ifndef CONTACTS_H
#define CONTACTS_H
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Contact{
    string name;
    map<string, string> phoneNums;


public:
    Contact(string n, string fk, string fv);
    ~Contact();
    Contact();
    void addNum(string key, string val);
    void deleteNum(string key);
    void editNum(string key, string val);
    void displayNum();

};

class Contacts{
    map<string, Contact> contacts;
    vector<string> favs;
public:
    Contacts();
    ~Contacts();
    void addContact(string n, string fk, string fv);
    void deleteContact(string n);
    void editContact(string n, string newN);

    void addContactPH(string n, string t, string p);
    void editContactPH(string n, string t, string p);
    void deleteContactPH(string n, string t);
    void addFav(string n);
    void remFav(string n);
    void displayContact(string n);
    void displayFav();
    void searchContact(string str);
};






#endif
