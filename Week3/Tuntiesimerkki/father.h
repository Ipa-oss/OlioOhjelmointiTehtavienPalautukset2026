#ifndef FATHER_H
#define FATHER_H
#include <string>
using namespace std;

class Father
{
public:
    Father(string);
    ~Father();
    void printFatherName();
    virtual void printEducation();
private:
    string FatherName;
protected:
    string FatherNickName;
};

#endif // FATHER_H
