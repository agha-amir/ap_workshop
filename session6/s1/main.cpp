#include "Shop.h"

int main(){

    Shop shop;

    shop.addCar("BMW i8", "BMW", "blue", 250 , 2017, 70000.48);
    shop.addMotor("yamaha YZF-R1M", "yamaha", "black", 180, 2024, 15000, 100);
    shop.addBicycle("Ibis Ripmo V2 XT", "Ibis", "Blue",30 , 2023, 50);
    shop.testItem(1);
    cout << "\nprinting the info of vehicle with id 1:" << endl;
    shop.display(1);
    cout << "printing the info of vehicle with id 2:" << endl;
    shop.display(2);
    cout << "printing the info of vehicle with id 3:" << endl;
    shop.display(3);
    cout << "printing the info of vehicle with id 4:" << endl;
    shop.display(4);
    cout<<endl;
    shop.sellItem(3);
    shop.rentItem(3, 10);
    shop.sellItem(1);
    shop.sellItem(1);
    shop.rentItem(3, 10);
    shop.rentItem(2, 5);
    shop.sellItem(2);
    shop.returnItem(2);
    shop.sellItem(2);
    return 0;
}

