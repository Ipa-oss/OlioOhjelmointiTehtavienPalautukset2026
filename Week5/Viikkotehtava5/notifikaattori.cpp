#include "notifikaattori.h"
#include <iostream>
using namespace std;

Notifikaattori::Notifikaattori() {
    cout<<"Luodaan notifikaattori."<<endl;
}

void Notifikaattori::lisaa(Seuraaja * follow)
{
    cout<<"Notifikaattori lisaa seuraajan: "<<follow->getNimi()<<endl;
    if(seuraajat == nullptr){
        seuraajat = follow;
    }else{
        follow->next = seuraajat;
        seuraajat = follow;
    }
}

void Notifikaattori::poista(Seuraaja * follow)
{
    cout<<"Notifikaattori poistaa seuraajan: "<<follow->getNimi()<<endl;
    Seuraaja * findPrev = seuraajat;
    while(findPrev && findPrev->next != follow){
        findPrev = findPrev->next;
    }
    findPrev->next = follow->next;
}

void Notifikaattori::tulosta()
{
    cout<<"Notifikaattorin seuraajat:"<<endl;
    Seuraaja * pointerPtr = seuraajat;
    while(pointerPtr != nullptr){
        cout<<"Seuraaja "<<pointerPtr->getNimi()<<endl;
        pointerPtr = pointerPtr->next;
    }
}

void Notifikaattori::postita(string alkViesti)
{
    cout<<"Notifikaattori postaa viestin: "<<alkViesti<<endl;
    Seuraaja * pointerPtr = seuraajat;
    while(pointerPtr != nullptr){
        pointerPtr->paivitys(alkViesti);
        pointerPtr = pointerPtr->next;
    }
}

