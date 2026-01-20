#ifndef SON_H
#define SON_H
#include <string>
#include "father.h"
using namespace std;

class Son : public Father
{
public:
    Son(string,string);
    ~Son();
    void printEducation() override;
private:
    string SonName;
};

#endif // SON_H
