#include "chef.h"
#include <iostream>

Chef::Chef(std::string name)
{
    chefName=name;
    std::cout<<"Chef "<<getName()<<" konstruktori."<<std::endl;
}

Chef::~Chef()
{
    std::cout<<"Chef "<<getName()<<" destruktori."<<std::endl;
}

std::string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int sal)
{
    int numOfSalad=sal/5;
    std::cout<<"Chef "<<getName()
            <<" with "<<sal
            <<" items can make salad "<<numOfSalad
            <<" portions."<<std::endl;
    return numOfSalad;
}

int Chef::makeSoup(int sou)
{
    int numOfSoup=sou/3;
    std::cout<<"Chef "<<getName()
            <<" with "<<sou
            <<" items can make soup "<<numOfSoup
            <<" portions."<<std::endl;
    return numOfSoup;
}
