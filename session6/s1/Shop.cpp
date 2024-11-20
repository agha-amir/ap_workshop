#include "Shop.h"

Sellable::Sellable(double prc):price(prc), isSold(0) {
}
Sellable::~Sellable() {}

int Vehicle::num = 0;
void Sellable::sell(){
    if(isSold){
        cout<<"cant be sold"<<endl;
    } else{
        cout<<"sold for price: "<< this->price<<endl;
        this->isSold = 1;
    }
}

Rentable::Rentable(double prc):isRented(0), dailyPrice(prc){
}

Rentable::~Rentable() {}

void Rentable::rent(int days) {
    if(isRented){
       cout<<"cant be rented"<<endl;
    } else{
        cout<<"rented for price: "<< this->dailyPrice * days<<endl;
        this->isRented = 1;
    }
}

void Rentable::returnFromRent() {
    this->isRented = 0;
}

Vehicle::Vehicle(string name, string man, string clr, int maxspd, int yr):model(name), manufacturer(man), year(yr), color(clr), maxSpeed(maxspd)
{
    num ++;
    this->id = num;
}

Vehicle::~Vehicle() {}


Car::Car(string name, string man, string clr, int maxspd, int yr, double prc) : Vehicle(name, man, clr, maxspd, yr),
                                                                                Sellable(prc){
}

Car::~Car() {}

Motorcycle::Motorcycle(string name, string man, string clr, int maxspd, int yr, double sellprc, double rentprc): Vehicle(name, man, clr, maxspd, yr),
                                                                                                                 Sellable(sellprc), Rentable(rentprc)
{}

Motorcycle::~Motorcycle() {}


Bicycle::Bicycle(string name, string man, string clr, int maxspd, int yr, double prc): Vehicle(name, man, clr, maxspd, yr),
                                                                                       Rentable(prc)
{}

Bicycle::~Bicycle() {}

void Vehicle::show() {
    cout << "manufacturer: " << manufacturer<< "\nmodel: " << model<< "\ncolor: " << color<< "\nyear: " << year<< "\nmax Speed: " << maxSpeed << endl;
}

void Car::show() {
    Vehicle::show();
    cout<<"price: "<<price<<endl<<endl;
}

void Motorcycle::show() {
    Vehicle::show();
    cout<<"price: "<<price<<endl<<"daily price: "<<dailyPrice<<endl<<endl;
}

void Bicycle::show() {
    Vehicle::show();
    cout<<"daily price: "<<dailyPrice<<endl<<endl;
}

void Car::drive() {
    for (int i = 0; i < maxSpeed; ++i) {
        cout<<i<<" ";
    }
}

void Motorcycle::drive() {
    for(int i = 0;i<maxSpeed/2;++i){
        cout<<i<<" ";
    }
}

void Bicycle::drive() {
    for (int i = 0; i < maxSpeed; ++i) {
        cout<<"pedaling"<<" ";
    }
}

Node::Node(Vehicle* v):item(v), next(nullptr) {}

Node::~Node() {}

Shop::Shop() :head(nullptr){
}

Shop::~Shop() {
    if(head == nullptr){return;}
    Node* current = head;
    Node* temp;
    while (current != nullptr){
        temp = current;
        current = current->next;
        temp->item = nullptr;
        delete temp->item;
        temp = nullptr;
        delete temp;
    }
}

bool Shop::addCar(string nm, string man, string clr, int yr, int maxspd, double prc) {
    Car* c = new Car(nm, man, clr, yr, maxspd, prc);
    Node* newNode = new Node(c);

    if(head == nullptr){
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return 1;
}

bool Shop::addMotor(string nm, string man, string clr, int yr, int maxspd, double sprc, double rprc) {
    Motorcycle* m = new Motorcycle (nm, man, clr, yr, maxspd, sprc, rprc);
    Node* newNode = new Node(m);
    if(head == nullptr){
        head = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
    return 1;
}

bool Shop::addBicycle(string nm, string man, string clr, int yr, int maxspd, double prc) {
    Bicycle* b = new Bicycle(nm, man, clr, yr, maxspd, prc);
    Node* newNode = new Node(b);

    if(head == nullptr){
        head = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
    return 1;
}

void Shop::testItem(int n) {
    Node* current = head;
    while (current != nullptr){
        if(current->item->getId() == n){
            current->item->drive();
            return;
        }
        current = current->next;
    }
    cout<<"item not found"<<endl;

}

void Shop::display(int n) {
    Node* current = head;
    while (current != nullptr){
        if (current->item->getId() == n) {current->item->show(); return;}
        current = current->next;
    }
        cout<<"item not found"<<endl;
}

bool Shop::rentItem(int n, int d) {
    Node* current = head;
    while (current != nullptr) {
        if (current->item->getId() == n) {
            Rentable* rnt = dynamic_cast<Rentable*>(current->item);
            if (rnt) {
                rnt->rent(d);
                return 1;
            } else {
                cout << "item is not rentable" << endl;
                return 0;
            }
        }
        current = current->next;
    }
    cout << "item not found" << endl;
    return 0;
}


bool Shop::sellItem(int n) {
    Node* current = head;
    Node* prevNode = nullptr;

    while (current != nullptr && current->item->getId() != n) {
        prevNode = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "item not found" << endl;
        return 0;
    }

    Sellable* sel = dynamic_cast<Sellable*>(current->item);
    Rentable* rnt = dynamic_cast<Rentable*>(current->item);
    if (!sel) {
        cout << "item is not sellable" << endl;
        return 0;
    }
    if(rnt && rnt->getIsRented()){
        cout << "item is not sellable" << endl;
        return 0;
    }

    sel->sell();
    if (prevNode == nullptr) {
        head = current->next;
    } else {
        prevNode->next = current->next;
    }
    delete current;
    return 1;
}



int Vehicle::getId() {
    return this->id;}

bool Rentable::getIsRented() {return isRented;}

bool Shop::returnItem(int n) {
    Node* current = head;
    while (current != nullptr) {
        if (current->item->getId() == n) {
            Rentable* rnt = dynamic_cast<Rentable*>(current->item);
            if (rnt) {
                rnt->returnFromRent();
                return 1;
            } else {
                cout << "item was not rentable" << endl;
                return 0;
            }
        }
        current = current->next;
    }
    cout << "item not found" << endl;
    return 0;
}

