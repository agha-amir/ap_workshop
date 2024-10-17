#include "LinkedList.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    LinkedList list1;
    LinkedList list2(4, 4);
    LinkedList listCpy(list2);

    cout<<list1.is_empty()<<endl;
    cout<<list2.is_empty()<<endl;

    cout<<list1.at(3)<<endl;
    cout<<list2.at(4)<<endl;
    cout<<list2.at(3)<<endl;

    cout<<list1.pop_back()<<endl;
    cout<<list1.pop_front()<<endl;

    list1.push_back(10);
    list2.push_back(3);
    list1.push_front(11);
    list2.push_front(5);

    cout<<list2.pop_back()<<endl;
    cout<<list2.pop_front()<<endl;

    cout<<endl<<endl<<endl;

    cout<<listCpy.is_empty()<<endl;
    cout<<listCpy.at(3)<<endl;
    listCpy.push_back(3);
    listCpy.push_front(5);
    cout<<listCpy.pop_back()<<endl;
    cout<<listCpy.pop_front()<<endl;
    return 0;
}
