#include "LinkedList.h"
#include <stdio.h>
#include <iostream>

Node::Node() {}
Node::~Node() {}

LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(int value, int size){
    head = nullptr;
    tail = nullptr;

    for (int i = 0; i < size; i++)
    {
        push_back(value);
    }
}


LinkedList::LinkedList(const LinkedList& Cloned){
    head = nullptr;
    tail = nullptr;

    Node* temp = Cloned.head;

    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->Next;
    }
    
}

LinkedList::~LinkedList(){
    while (!is_empty())
    {
        pop_back();
    }
    
}

void LinkedList::push_back(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->Next = nullptr;
    newNode->previous = tail;

    if (head == nullptr)
    {
        head = newNode;
    }
    if (tail != nullptr)
    {
        tail->Next = newNode;
    }
    tail = newNode;
}

void LinkedList::push_front(int value){
    Node* newNode = new Node;

    newNode->data = value;
    newNode->previous = nullptr;
    newNode->Next = head;

    if (tail == nullptr)
    {
        tail = newNode;
    }

    if (head != nullptr)
    {
        head->previous = newNode;
    }
    head = newNode;
}


int LinkedList::pop_back(){
    if (tail == nullptr)
    {

        return INT_MIN;
    }
    
    int value = tail->data;

    Node* temp = tail;
    tail = tail->previous;

    if (tail != nullptr)
    {
        tail->Next = nullptr;
    }

    else{
        head = nullptr;
    }
    
    delete temp;

    return value;
}

int LinkedList::pop_front(){
    if (head == nullptr)
    {
        return INT_MIN;
    }
    int value = head->data;
    Node* temp = head;
    head = head->Next;

    if (head != nullptr)
    {
        head->previous = nullptr;
    }

    else{
        tail = nullptr;
    }
    delete temp;
    return value;
}

bool LinkedList::is_empty(){
    if (head == nullptr)
    {
        return 1;
    }
    return 0;
}

int LinkedList::at(int index){
    if (index < 0)
    {
        cout<<"index should be non negative"<<endl;
        return INT_MIN;
    }
    

    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        if (cnt == index)
        {
            return temp->data;
        }
        cnt ++;
        temp = temp->Next;
    }
    cout<<"index should be smaller than array's size"<<endl;
    return INT_MIN;
}
