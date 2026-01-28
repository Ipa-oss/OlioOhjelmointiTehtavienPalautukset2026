#include "pankkitili.h"
#include <iostream>
using namespace std;

Pankkitili::Pankkitili(string name) {
    omistaja = name;
    cout<<"Pankkitili luotu "<<omistaja<<":lle."<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double in)
{
    if(in<=0){
        cout<<"Et voi tallentaa summaa joka on nolla tai pienempi."<<endl;
        return false;
    }else{
        saldo=saldo+in;
        cout<<"Kayttotili: talletus "<<in<<" tehty."<<endl;
        return true;
    }
}

bool Pankkitili::withdraw(double out)
{
    if(out<=0){
        cout<<"Et voi nostaa summaa joka on nolla tai pienempi."<<endl;
        return false;
    }else if(saldo<=out){
        cout<<"Tilin saldo on liian pieni nostolle."<<endl;
        return false;
    }else{
        saldo=saldo-out;
        cout<<"Kayttotili: nosto "<<out<<" tehty."<<endl;
        return true;
    }
}
