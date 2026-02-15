#include "student.h"


Student::Student(string s, int n)
{
    name = s;
    studentNumber = n;
}

string Student::getName()
{
    return name;
}

int Student::getNumber()
{
    return studentNumber;
}
