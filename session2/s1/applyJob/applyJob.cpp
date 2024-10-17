#include <iostream>
#include "applyJob.h"
using namespace std;

void analyze(int* pointer, int& reference){
    if (pointer == nullptr)
    {
        cout<<"pointer is null"<<endl;
        return;
    }

    cout<<"the pointer is: "<< pointer<<endl;
    cout<<"the reference is:" << &reference<<endl;

    if (reference == *pointer)
    {
        cout<<"value of the pointer and the reference is the same" << endl;
    }
    if (&reference == pointer && reference == *pointer)
    {
        cout<<"value and variable of the pointer and the reference is the same" << endl;
    }
    if (reference == *pointer && &reference != pointer)
    {
        cout<<"value is the same but variables are different" << endl;
    }
    if(reference != *pointer && &reference != pointer){
        cout<<"neither the value nor the variable of the pointer and the reference are the same" << endl;
    }
    
}