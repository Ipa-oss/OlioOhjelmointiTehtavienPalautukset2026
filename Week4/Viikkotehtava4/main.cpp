#include <iostream>
#include "asiakas.h"

int main()
{
    Asiakas aa("Aapeli",1000);
    aa.showSaldo();
    std::cout<<std::endl;
    aa.talletus(250);
    aa.luotonNosto(150);
    aa.showSaldo();
    std::cout<<std::endl;
    Asiakas be("Bertta",1000);
    be.showSaldo();
    std::cout<<std::endl;
    aa.tiliSiirto(50,be);
}
