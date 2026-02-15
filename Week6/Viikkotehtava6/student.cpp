#include <iostream>
#include "student.h"

Student::Student(string nimi, int ika)
{
    Name=nimi;
    Age=ika;
}

void Student::setAge(int ika)
{
    Age=ika;
}

void Student::setName(string nimi)
{
    Name=nimi;
}

int Student::getAge()
{
    return Age;
}

string Student::getName()
{
    return Name;
}

void Student::printStudentInfo()
{
    cout<<"Student: "<<getName()<<", Age: "<<getAge()<<endl;
}
