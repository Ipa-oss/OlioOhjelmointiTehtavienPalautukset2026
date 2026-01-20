#ifndef CHEF_H
#define CHEF_H
#include <string>

class Chef
{
public:
    Chef(std::string);
    ~Chef();
    std::string getName();
    int makeSalad(int);
    int makeSoup(int);
protected:
    std::string chefName;
};

#endif // CHEF_H
