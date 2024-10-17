#include <iostream>
#include "applyJob.h"
using namespace std;
int main(){

int val1 = 5;
int val2 = 5;
int val3 = 6;

//case 1: values are equal but variables are diffesrent
int* pointer1 = new int;
*pointer1 = val1;
int& reference1 = val2;
analyze(pointer1, reference1);
delete pointer1;


cout<<"\n\n\n";

//case 2: values and variables are equal
int& reference2 = val1;
int* pointer2 = &val1;
analyze(pointer2, reference2);

cout<<"\n\n\n";

//case 3: neither values nor variables are equal
int* pointer3 = new int;
*pointer3 = val3;
int& reference3 = val1;
analyze(pointer3, reference3);
delete pointer3;

//case 4: null pointer handling
cout<<"\n\n\n";
analyze(nullptr, reference3);

return 0;
}
