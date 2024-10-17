#include "human.h"
#include <iostream>
#include <string.h>
using namespace std;

void target_sec(Human * human, int n){
    int tempIndex = 0;
    int secMostAge = human[0].age;
    for (int i = 0; i < n; i++)
    {
        if (human[i].age > secMostAge)
        {
            secMostAge = human[i].age;
            tempIndex = i;
        }
    }
    
    secMostAge = 0;
    int index = 0;
    for (int j = 0; j < n; j++)
    {
        if (human[j].age > secMostAge && j != tempIndex)
        {
            secMostAge = human[j].age;
            index = j;
        }
    }
    cout<<"the human with the second most age is: "<<endl;
    cout<<human[index].name<<" "<<human[index].family<<endl<<endl;
}

void target_sec(Student * student, int n){
    int tempIndex = 0;
    double secMostAvg = student[0].avg;
    for (int i = 0; i < n; i++)
    {
        if (student[i].avg > secMostAvg)
        {
            secMostAvg = student[i].avg;
            tempIndex = i;
        }
    }
    
    secMostAvg = 0;
    int index = 0;
    for (int j = 0; j < n; j++)
    {
        if (student[j].avg > secMostAvg && j != tempIndex)
        {
            secMostAvg = student[j].avg;
            index = j;
        }
    }

    cout<<"the student with the second most avg is: "<<endl;
    cout<<student[index].h.name<<" "<<student[index].h.family<<endl<<endl;
}

void target_sec(Student * student, int n, bool v){
    if (!v)
    {
        int tempIndex = 0;
        double secMostAge = student[0].h.age;
        for (int i = 0; i < n; i++)
        {
            if (student[i].h.age > secMostAge)
            {
                secMostAge = student[i].h.age;
                tempIndex = i;
            }
        }

        secMostAge = 0;
        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (student[j].h.age > secMostAge && j != tempIndex)
            {
                secMostAge = student[j].h.age;
                index = j;
            }
        }

        cout<<"the student with the second most age is: "<<endl;
        cout<<student[index].h.name<<" "<<student[index].h.family<<endl;
        }
    

    else{
        int tempIndex = 0;
        double secMostAvg = student[0].avg;
        for (int i = 0; i < n; i++)
        {
            if (student[i].avg > secMostAvg)
            {
                secMostAvg = student[i].avg;
                tempIndex = i;
            }
        }

        secMostAvg = 0;
        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (student[j].avg > secMostAvg && j != tempIndex)
            {
                secMostAvg = student[j].avg;
                index = j;
            }
        }

        cout<<"the student with the second most avg is: "<<endl;
        cout<<student[index].h.name<<" "<<student[index].h.family<<endl;
        }
    cout<<endl;

}


void createHuman(Human& human, const char* name, const char* family, int n_code, int age){
    int size = strlen(family);
    human.family = new char[size];
    strcpy(human.name, name);
    strcpy(human.family, family);
    human.age = age;
    human.n_code = n_code;
}

void createStudent(Student& student, Human& human, /*char name, char family, int n_code, int age,*/ int std_no, double avg, const char* field){
    // int size = strlen(&family);
    // human.family = new char[size];
    // strcpy(human.name, &name);
    // strcpy(human.family, &family);
    // human.age = age;
    // human.n_code = n_code;
    student.h = human;
    strcpy(student.field, field);
    student.avg = avg;
    student.std_no = std_no;
}

void deleteHuman(Human& human){
    delete[] human.family;
    //delete human.name;
    strcpy(human.name, nullptr);
    strcpy(human.family, nullptr);
}

void deleteStudent(Student& student){
    delete[] student.h.family;

    strcpy(student.field, nullptr);
    strcpy(student.h.name, nullptr);
    strcpy(student.h.family, nullptr);
}

