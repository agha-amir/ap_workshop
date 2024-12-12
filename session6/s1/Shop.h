#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <iostream>
using namespace std;

class Vehicle{
protected:
    int id;
    int maxSpeed;
    string manufacturer;
    string model;
    string color;
    int year;
public:
    static int num;
    Vehicle(string, string, string, int, int);
    ~Vehicle();
    virtual void drive() = 0;
    virtual void show() = 0;
    int getId();
};


class Sellable{
protected:
    double price;
    bool isSold;
public:
    Sellable(double);
    ~Sellable();
    void sell();
};

class Rentable{
protected:
    double dailyPrice;
    bool isRented;
public:
    Rentable(double);
    ~Rentable();
    bool getIsRented();
    void rent(int);
    void returnFromRent();
};


class Car:public Sellable, public Vehicle{
public:
    Car(string, string, string, int, int, double);
    ~Car();
    void drive();
    void show() override;
};

class Motorcycle:public Sellable, public Rentable, public Vehicle{
public:
    Motorcycle(string, string, string, int, int, double, double);
    ~Motorcycle();
    void drive();
    void show() override;
};

class Bicycle:public Rentable, public Vehicle{
public:
    Bicycle(string, string, string, int, int, double);
    ~Bicycle();
    void drive();
    void show() override;
};

class Node{
public:
    Node* next;
    Vehicle* item;
    Node(Vehicle*);
    ~Node();
};

class Shop{
    Node* head;
public:
    Shop();
    ~Shop();
    void display(int);
    bool addCar(string, string, string, int, int, double);
    bool addMotor(string, string, string, int, int, double, double);
    bool addBicycle(string, string, string, int, int, double);
    bool sellItem(int);
    bool rentItem(int, int);
    bool returnItem(int);
    void testItem(int);
};


#endif
