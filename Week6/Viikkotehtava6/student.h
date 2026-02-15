#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
public:
    Student(string,int);
    void setAge(int);
    void setName(string);
    int getAge();
    string getName();
    void printStudentInfo();
private:
    string Name;
    int Age;
};

#endif // STUDENT_H
