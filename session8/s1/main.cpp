#include "Contacts.h"

int main(){
    int choice;
    Contacts book;
    do{

        cout<<"choose an option: \n\n";
        cout<<"1. add contact\n";
        cout<<"2. edit contact\n";
        cout<<"3. delete contact\n";
        cout<<"4. add num\n";
        cout<<"5. edit num\n";
        cout<<"6. delete num\n";
        cout<<"7. add fav\n";
        cout<<"8. delete fav\n";
        cout<<"9. display contacts\n";
        cout<<"10. display fav\n";
        cout<<"0. exit\n";
        cin>>choice;
        switch (choice) {
            case 1:{
                string n, fk, fv;
                cout<<"name: \n";
                getchar();
                getline(cin, n);
                cout<<"\nnum type: \n";
                getline(cin, fk);
                cout<<"\nnum: \n";
                getline(cin, fv);
                book.addContact(n, fk, fv);
                break;
            }
            case 2:{
                string n, newN;
                cout<<"name: ";
                cin>>n;
                cout<<"\nnew name: ";
                cin>>newN;
                book.editContact(n, newN);
                break;
            }
            case 3:{
                string n;
                cout<<"name: ";
                cin>>n;
                book.deleteContact(n);
                break;
            }
            case 4:{
                string n, t, p;
                cout<<"name: ";
                cin>>n;
                cout<<"\nnum type: ";
                cin>>t;
                cout<<"\nnum: ";
                cin>>p;
                book.addContactPH(n, t, p);
                break;
            }
            case 5:{
                string n, t, p;
                cout<<"name: ";
                cin>>n;
                cout<<"\nnum type: ";
                cin>>t;
                cout<<"\nnew num: ";
                cin>>p;
                book.editContactPH(n, t, p);
                break;
            }
            case 6:{
                string n, t;
                cout<<"name: ";
                cin>>n;
                cout<<"\nnum type: ";
                cin>>t;
                book.deleteContactPH(n, t);
                break;
            }
            case 7:{
                string n;
                cout<<"name: ";
                cin>>n;
                book.addFav(n);
                break;
            }
            case 8:{
                string n;
                cout<<"name: ";
                cin>>n;
                book.remFav(n);
                break;
            }
            case 9:{
                string n;
                cout<<"name: ";
                getchar();
                getline(cin, n);
                cout<<n<<endl;
                book.displayContact(n);
                break;
            }
            case 10:{
                book.displayFav();
                break;
            }
        }
    } while (choice!=0);

    return 0;
}

