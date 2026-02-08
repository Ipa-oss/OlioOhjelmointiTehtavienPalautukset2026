#include "seuraaja.h"
#include <iostream>
using namespace std;

Seuraaja::Seuraaja(string Name) {
    nimi = Name;
    cout<<"Luodaan seuraaja: "<<getNimi()<<endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout<<"Seuraaja "<<getNimi()<<" sai viestin: "<<viesti<<endl;
}
