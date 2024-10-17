#include "human.h"
#include <iostream>
using namespace std;
#include <cstring>

int main()
{
    int size = 5;
    Human* human = new Human[size];
    Student* student = new Student[size];

    for (int i = 0; i < size; i++)
    {
        human[i].family = new char[30]; //family allocation
    }
    

    createHuman(human[0], "amir", "ghoreishi", 120000005, 28);
    createStudent(student[0], human[0], 489654, 18.5, "CE");


    createHuman(human[1], "ali", "alian", 1270000000, 20);
    createStudent(student[1], human[1], 894656, 18.0, "EE");


    createHuman(human[2], "hossein", "hosseini", 1270000001, 19);
    createStudent(student[2], human[2], 489654, 18.2, "CE");



    createHuman(human[3], "mohammad", "mohammadi", 1270000002, 22);
    createStudent(student[3], human[3], 654981, 18.3, "CE");


    createHuman(human[4], "amir", "mohammadi", 1270000003, 25);
    createStudent(student[4], human[4], 9841946, 17.7, "CE");


    target_sec(human, size);
    target_sec(student, size);
    target_sec(student, size, false);
    target_sec(student, size, true);

    for (int i = 0; i < size; i++)
    {
        deleteHuman(human[i]);
        deleteStudent(student[i]);
    }

    delete[] human;
    delete[] student;


    //we cant put a default value for "bool v" because it will have conflict with the function overload No.2 [void target_sec(Student * student, int n);]
    return 0;
}

