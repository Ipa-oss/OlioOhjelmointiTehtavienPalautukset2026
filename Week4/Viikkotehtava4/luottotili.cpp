#include "luottotili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string nimi,double raja):Pankkitili(nimi) {
    omistaja = nimi;
    luottoRaja = raja;
    saldo = luottoRaja;
    cout<<"Luottotili luotu "<<omistaja<<":lle, luottoraja: "<<luottoRaja<<endl;
}

bool Luottotili::deposit(double in)
{
    if(in<=0){
        cout<<"Et voi maksaa summaa joka on nolla tai pienempi."<<endl;
        return false;
    }else if(saldo+in>=luottoRaja){
        cout<<"Maksamasi summa on liian suuri."<<endl;
        return false;
    }else{
        saldo=saldo+in;
        cout<<"Luottotili: talletus "<<in<<" tehty, luottoa jaljella: "<<saldo<<endl;
        return true;
    }
}

bool Luottotili::withdraw(double out)
{
    if(out<=0){
        cout<<"Et voi nostaa summaa joka on nolla tai pienempi."<<endl;
        return false;
    }else if(saldo-out<=0){
        cout<<"Tilin saldo on liian pieni nostolle."<<endl;
        return false;
    }else{
        saldo=saldo-out;
        cout<<"Luottotili: nosto "<<out<<" tehty, luottoa jaljella: "<<saldo<<endl;
        return true;
    }
}
