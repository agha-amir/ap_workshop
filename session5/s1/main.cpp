#include "Message.h"
using namespace std;
#include <iostream>
#include <string>
int main(){
    bool isValid = 0;
    string* userArray = new string[2];
    string* passwdArray = new string[2];
    userArray[0] = "amir";
    userArray[1] = "gh";
    passwdArray[0] = "1234";
    passwdArray[1] = "5678";
    do {

        string username;
        string passwd;
        cout<<"login: "<<endl;
        cout<<"username: "<<endl;
        cin>>username;
        cout<<"password: "<<endl;
        cin>>passwd;
        for (int i=0; i<2; ++i){
            if(userArray[i] == username && passwdArray[i] == passwd){
                isValid = 1;
            }
        }
        if(!isValid){cout<<"wrong username or password"<<endl;}
    } while (!isValid);
    int choice;
    BaseMessage* allMessages[100];
    int size = 0;

    do {
        cout<<"1. simple message"<<endl;
        cout<<"2. post message"<<endl;
        cout<<"3. vote"<<endl;
        cout<<"4. quiz"<<endl;
        cout<<"5. print all messages"<<endl;
        cout<<"0. exit"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:{
                int d, m, y, si, ri;
                string sn,rn, msg;
                cout<<"day: "<<endl;
                cin>>d;
                cout<<endl<<"month: "<<endl;
                cin>>m;
                cout<<endl<<"year: "<<endl;
                cin>>y;
                cout<<endl<<"your name: "<<endl;
                cin>>sn;
                cout<<endl<<"your id: "<<endl;
                cin>>si;
                cout<<endl<<"receiver's name: "<<endl;
                cin>>rn;
                cout<<endl<<"receiver's id: "<<endl;
                cin>>ri;
                cout<<endl<<"your massage: "<<endl;
                cin>>msg;
                SimpleMessage* smsg = new SimpleMessage(msg, d, m, y, sn, si, rn, ri);
                allMessages[size] = smsg;
                delete smsg;
                size++;
                break;
            }
            case 2:{
                int d, m, y, si, ri;
                string sn, rn, msg, imgp;
                cout<<"day: "<<endl;
                cin>>d;
                cout<<endl<<"month: "<<endl;
                cin>>m;
                cout<<endl<<"year: "<<endl;
                cin>>y;
                cout<<endl<<"your name: "<<endl;
                cin>>sn;
                cout<<endl<<"your id: "<<endl;
                cin>>si;
                cout<<endl<<"receiver's name: "<<endl;
                cin>>rn;
                cout<<endl<<"receiver's id: "<<endl;
                cin>>ri;
                cout<<endl<<"your massage: "<<endl;
                cin>>msg;
                cout<<endl<<"image's path"<<endl;
                cin>>imgp;
                PostMessage* pmsg = new PostMessage(imgp, msg, d, m, y, sn, si, rn, ri);
                allMessages[size] = pmsg;
                delete pmsg;
                size++;
                break;
            }
            case 3:{
                int d, m, y, rightOption, si, ri;
                string vt, sn, rn;
                cout<<"day: "<<endl;
                cin>>d;
                cout<<endl<<"month: "<<endl;
                cin>>m;
                cout<<endl<<"year: "<<endl;
                cin>>y;
                cout<<endl<<"your name: "<<endl;
                cin>>sn;
                cout<<endl<<"your id: "<<endl;
                cin>>si;
                cout<<endl<<"receiver's name: "<<endl;
                cin>>rn;
                cout<<endl<<"receiver's id: "<<endl;
                cin>>ri;
                cout<<endl<<"enter vote title"<<endl;
                cin>>vt;
                string* opts = new string[10];
                cout<<endl<<"enter 10 options"<<endl;
                for (int i = 0; i < 10; ++i) {
                    cin>>opts[i];
                    cout<<endl;
                }

                cout<<endl<<"which one is the answer?"<<endl;
                cin>>rightOption;
                VoteMessage* qmsg = new VoteMessage(vt, 1, opts, d, m, y, sn, si, rn, ri);
                qmsg->setRightOption(opts[rightOption]);
                allMessages[size] = qmsg;
                delete qmsg;
                size++;
                break;
            }
            case 4:{
                int d, m, y, si, ri;
                string vt, sn, rn;
                cout<<"day: "<<endl;
                cin>>d;
                cout<<endl<<"month: "<<endl;
                cin>>m;
                cout<<endl<<"year: "<<endl;
                cin>>y;
                cout<<endl<<"your name: "<<endl;
                cin>>sn;
                cout<<endl<<"your id: "<<endl;
                cin>>si;
                cout<<endl<<"receiver's name: "<<endl;
                cin>>rn;
                cout<<endl<<"receiver's id: "<<endl;
                cin>>ri;
                cout<<endl<<"enter vote title"<<endl;
                cin>>vt;
                string* opts = new string[10];
                cout<<endl<<"enter 10 options"<<endl;
                for (int i = 0; i < 10; ++i) {
                    cin>>opts[i];
                    cout<<endl;
                }
                VoteMessage* vmsg = new VoteMessage(vt, 0, opts, d, m, y, sn, si, rn, ri);
                allMessages[size] = vmsg;
                delete vmsg;
                size++;
                break;
            }

            case 5:{
                for (int i = 0; i < size; ++i) {
                    allMessages[i]->print();
                }
            }
        }
    } while (choice != 0);

    return 0;
}


