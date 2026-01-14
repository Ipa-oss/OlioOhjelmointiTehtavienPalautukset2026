//OSA1,2 JA 3
#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int suurin=0;
    cout<<"Anna suurin luku, jonka haluat pelin arpovan."<<endl;
    cin>>suurin;
    Game peli(suurin);
    peli.play();
}
