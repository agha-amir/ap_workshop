#include <iostream>
#include "sickArray.h"
using namespace std;

void newArray(int**& arr, int& n){
    arr = new int*[n+1];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < 3; j++)
        {
            *(*(arr +i) + j) = i+j;
        }
    }
    arr[n] = nullptr;
}

void squareArray(int**& arr){
    int n = 0;
    int** current = arr;

    while (*current != nullptr) {
        n++;
        current++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(arr +i) + j) *= *(*(arr +i) + j);
            //cout<<*(*(arr +i) + j)<<endl;
        }
    }
}

void printArray(int**& arr){
    int n = 0;
    int** current = arr;

    while (*current != nullptr) {
        n++;
        current++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<*(*(arr +i) + j);
        }
    }
    cout<<endl;
}

void freeArray(int**& arr){
    int n = 0;
    int** current = arr;

    while (*current != nullptr) {
        n++;
        current++;
        for (int i = 0; i < n; i++)
        {
        delete[]*(arr +i);
        }
    }delete[]arr;


}