#ifndef REVERSEPRINT_H
#define REVERSEPRINT_H
using namespace std;

class Node{
public:
    int value;
    Node(int);
    ~Node();
    Node* next;
};

class list{
private:
    Node* head;
    void reversePrint(Node*);
public:
    list();
    ~list();
    void appendFirst(const int);
    void printList(bool);
};


#endif
