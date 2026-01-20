#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef kokki("Gordon");
    kokki.makeSalad(11);
    kokki.makeSoup(14);
    std::cout<<std::endl;
    ItalianChef itakokki("Mario");
    itakokki.makeSalad(9);
    itakokki.askSecret("pizza",12,12);
    return 0;
}
