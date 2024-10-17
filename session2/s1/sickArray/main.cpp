#include <iostream>
#include "sickArray.h"
using namespace std;


int main()
{
    int num{3};
    int** array;
    int &n = num;
    int**& arr = array;
    newArray(arr, n);
    printArray(arr);
    squareArray(arr);
    printArray(arr);
    freeArray(arr);
    printArray(arr);
}

