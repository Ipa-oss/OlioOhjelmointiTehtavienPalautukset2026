#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"
#include <string>

class ItalianChef : public Chef
{
public:
    ItalianChef(std::string);
    ~ItalianChef();
    bool askSecret(std::string,int,int);
private:
    std::string password = "pizza";
    int flour;
    int water;
    int makepizza(int,int);
};

#endif // ITALIANCHEF_H
