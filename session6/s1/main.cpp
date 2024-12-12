#include "Shop.h"

int main(){

    Shop shop;
    int choice;
    do {
        cout<<"\n\nchose an option: "<<endl;
        cout<<"1. add car\n";
        cout<<"2. add motorcycle\n";
        cout<<"3. add bicycle\n";
        cout<<"4. rent a vehicle\n";
        cout<<"5. sell a vehicle\n";
        cout<<"6. return a vehicle from rent\n";
        cout<<"7. display a vehicle's info\n";
        cout<<"8. test a vehicle\n";
        cout<<"0. exit\n";
        cin>>choice;
        switch (choice) {
            case 1:{
                string model, man, color;
                int maxSpeed, year;
                double price;
                cout<<"model: ";
                cin>>model;
                cout<<"\nmanufacturer: ";
                cin>>man;
                cout<<"\ncolor";
                cin>>color;
                cout<<"\nmax speed: ";
                cin>>maxSpeed;
                cout<<"\nyear: ";
                cin>>year;
                cout<<"\nsell price: ";
                cin>>price;
                shop.addCar(model, man, color, maxSpeed, year, price);
                break;
            }
            case 2:{
                string model, man, color;
                int maxSpeed, year;
                double price, rentPrice;
                cout<<"model: ";
                cin>>model;
                cout<<"\nmanufacturer: ";
                cin>>man;
                cout<<"\ncolor";
                cin>>color;
                cout<<"\nmax speed: ";
                cin>>maxSpeed;
                cout<<"\nyear: ";
                cin>>year;
                cout<<"\nsell price: ";
                cin>>price;
                cout<<"\nrent price: ";
                cin>>rentPrice;
                shop.addMotor(model, man, color, maxSpeed, year, price, rentPrice);
                break;
            }

            case 3:{
                string model, man, color;
                int maxSpeed, year;
                double price;
                cout<<"model: ";
                cin>>model;
                cout<<"\nmanufacturer: ";
                cin>>man;
                cout<<"\ncolor";
                cin>>color;
                cout<<"\nmax speed: ";
                cin>>maxSpeed;
                cout<<"\nyear: ";
                cin>>year;
                cout<<"\nrent price: ";
                cin>>price;
                shop.addBicycle(model, man, color, maxSpeed, year, price);
                break;
            }
            case 4:{
                cout<<"\n\n enter vehicle's id: ";
                int id, d;
                cin>>id;
                cout<<"\n how many days would you want to rent? ";
                cin>>d;
                shop.rentItem(id, d);
                break;
            }
            case 5:{
                cout<<"\n\n enter vehicle's id: ";
                int id;
                cin>>id;
                shop.sellItem(id);
                break;
            }
            case 6:{
                cout<<"\n\n enter vehicle's id: ";
                int id;
                cin>>id;
                shop.returnItem(id);
                break;
            }
            case 7:{
                cout<<"\n\n enter vehicle's id: ";
                int id;
                cin>>id;
                shop.display(id);
                break;
            }
            case 8:{
                cout<<"\n\n enter vehicle's id: ";
                int id;
                cin>>id;
                shop.testItem(id);
                break;
            }
        }

    } while (choice !=0 );

//    shop.addCar("BMW i8", "BMW", "blue", 250 , 2017, 70000.48);
//    shop.addMotor("yamaha YZF-R1M", "yamaha", "black", 180, 2024, 15000, 100);
//    shop.addBicycle("Ibis Ripmo V2 XT", "Ibis", "Blue",30 , 2023, 50);
//    shop.testItem(1);
//    cout << "\nprinting the info of vehicle with id 1:" << endl;
//    shop.display(1);
//    cout << "printing the info of vehicle with id 2:" << endl;
//    shop.display(2);
//    cout << "printing the info of vehicle with id 3:" << endl;
//    shop.display(3);
//    cout << "printing the info of vehicle with id 4:" << endl;
//    shop.display(4);
//    cout<<endl;
//    shop.sellItem(3);
//    shop.rentItem(3, 10);
//    shop.sellItem(1);
//    shop.sellItem(1);
//    shop.rentItem(3, 10);
//    shop.rentItem(2, 5);
//    shop.sellItem(2);
//    shop.returnItem(2);
//    shop.sellItem(2);
    return 0;
}

