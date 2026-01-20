#include "italianchef.h"
#include <algorithm>
#include <iostream>

ItalianChef::ItalianChef(std::string name) : Chef(name)
{
    chefName=name;
    std::cout<<"ItalianChef "<<getName()<<" konstruktori."<<std::endl;
}

ItalianChef::~ItalianChef()
{
    std::cout<<"ItalianChef "<<getName()<<" destruktori."<<std::endl;
}

bool ItalianChef::askSecret(std::string secret, int flo, int wat)
{
    if(secret.compare(password) == 0){
        std::cout<<"Password ok!"<<std::endl;
        makepizza(flo,wat);
        return true;
    }
    return false;
}

int ItalianChef::makepizza(int flo, int wat)
{
    flour=flo/5;
    water=wat/5;
    std::cout<<"ItalianChef "<<getName()
            <<" with "<<flo
            <<" flour and "<<wat
            <<" water can make "<<std::min(flour,water)
            <<" pizzas."<<std::endl;
    return std::min(flour,water);
}
