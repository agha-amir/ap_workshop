#include "ReversePrint.h"
#include <iostream>
using namespace std;

Node::Node(int d):value(d), next(nullptr) {}

Node::~Node() {}

list::list():head(nullptr) {
}

list::~list() {}

void list::appendFirst(const int d) {
    Node* newNode = new Node(d);
    if(head == nullptr){head = newNode;return;}
    Node * temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void list::printList(bool b) {
    if(b){
        while (head != nullptr){
            cout<<head->value<<endl;
            head = head->next;
        }
    }

    else{reversePrint(head);}
}

void list::reversePrint(Node* current) {
    if(current == nullptr){
        return;
    }
    reversePrint(current->next);
    cout<<current->value<<endl;

}