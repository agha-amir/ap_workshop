#ifndef MSSAGE_H
#define MSSAGE_H
using namespace std;
#include <iostream>
#include <string>



class User{
private:
    string name;
    int id;
public:
    void setName(string);
    void setID(int);
    User();
    User(string, int);
    ~User();
    string getName();
    int getID();

};


class Date{
public:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int, int, int);
    ~Date();
    friend ostream& operator<<(ostream&, const Date&);
};

class BaseMessage
{
protected:
    Date date;
    User sender;
    User receiver;

public:
    BaseMessage();
    BaseMessage(int, int, int, string, int, string, int);
    ~BaseMessage();
    void printDate();
    virtual void print();
};

class SimpleMessage : public BaseMessage
{
public:
    SimpleMessage();
    SimpleMessage(string, int, int, int, string, int, string, int);
    ~SimpleMessage();
    void print();

protected :
    string msg;
};

class PostMessage : public SimpleMessage
{
public:
    PostMessage();
    PostMessage(string,string, int, int, int, string, int, string, int);
    ~PostMessage();
    void print();
private :
    string imgPath;
};

class VoteMessage : public BaseMessage
{
public:
    VoteMessage();
    VoteMessage(string, bool, string*, int, int, int, string, int, string, int);
    void setRightOption(const string&);
    ~VoteMessage();
    void print();
private :
    bool isQuiz;
    string rightOption;
    string voteTitle;
    string options[10];
};


#endif
