#include <iostream>
using namespace std;

struct human
{
    char name[30];
    char * family;
    int n_code;
    int age;
};
struct student
{
    human h;
    int std_no;
    char field[50];
    double avg;
};

typedef struct human Human;
typedef struct student Student;

void target_sec(Human * human, int n);
void target_sec(Student * student, int n);
void target_sec(Student * student, int n, bool v);
void createHuman(Human& human, const char* name, const char* family, int n_code, int age);
void createStudent(Student& student, Human& human/*, char name, char family, int& n_code, int& age*/, int std_no, double avg, const char* field);

void deleteHuman(Human& human);
void deleteStudent(Student& student);