#include "Message.h"
#include <iostream>

using namespace std;

User::User():id(0), name(""){}
User::User(string n, int i):name(n), id(i){}
User::~User() {}

Date::Date() :day(0), month(0), year(0){}
Date::Date(int d, int m, int y):day(d), month(m), year(y) {}
Date::~Date() {}

BaseMessage::BaseMessage(){}
BaseMessage::BaseMessage(int d, int m, int y, string sn, int si, string rn, int ri) {
    Date D(d, m, y);
    User S(sn, si);
    User R(rn, ri);
    date = D;
    sender = S;
    receiver = R;
}
BaseMessage::~BaseMessage() {}

SimpleMessage::SimpleMessage():msg(" "){}
SimpleMessage::SimpleMessage(string ms, int d, int m, int y, string sn, int si, string rn, int ri): BaseMessage(d, m, y, sn, si, rn, ri) {
    msg = ms;
}
SimpleMessage::~SimpleMessage() {}

PostMessage::PostMessage():imgPath(" ") {}
PostMessage::PostMessage(string imgp, string ms, int d, int m, int y, string sn, int si, string rn, int ri):SimpleMessage(ms, d, m, y, sn, si, rn, ri) {
    imgPath = imgp;
}


PostMessage::~PostMessage() {
}


VoteMessage::VoteMessage() :voteTitle(" "){}
VoteMessage::VoteMessage(string vt, bool b, string* o, int d, int m, int y, string sn, int si, string rn, int ri):BaseMessage(d, m, y, sn, si, rn, ri) {
    voteTitle = vt;
    isQuiz = b;
    //options = new string[10];
    for (int i = 0; i < 10; ++i) {
        o[i] = options[i];
    }
}
VoteMessage::~VoteMessage() {}


void BaseMessage::printDate() {
    cout << this->date;
    cout<< this->sender.getName()<<endl;
    cout<<this->sender.getID()<<endl;
}

ostream& operator<<(ostream& out, const Date& d) {
    out<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
    return out;
}

string User::getName() {
    return this->name;
}

int User::getID() {
    return this->id;
}


void User::setName(string n){
    this->name = n;
}

void User::setID(int i) {
    this->id = i;
}

void VoteMessage::setRightOption(const string & ro) {
    rightOption = ro;
}

void BaseMessage::print() {
    cout<<endl<<endl;
    this->printDate();
}

void SimpleMessage::print() {
    BaseMessage::print();
    cout<<"message: "<<this->msg<<endl;
}

void PostMessage::print() {
    SimpleMessage::print();
    cout<< this->imgPath<<endl;
}

void VoteMessage::print() {
    BaseMessage::print();
    cout<<"vote title"<<this->voteTitle<<endl;
    if(this->isQuiz){
        cout<<"right option: "<<this->rightOption<<endl;
    }
    cout<<"vote options: ";
    for (int i = 0; i < 10; ++i) {
        cout<< this->options[i]<<endl;
    }
}