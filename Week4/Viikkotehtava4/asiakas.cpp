#include "asiakas.h"
#include <iostream>
using namespace std;

Asiakas::Asiakas(string asiak, double raja):kayttotili(asiak),luottotili(asiak,raja) {
    nimi=asiak;
    cout<<"Asiakkuus luotu: "<<getNimi()<<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<"Kayttotilin saldo: "<<kayttotili.getBalance()<<endl;
    cout<<"Luottotilin saldo: "<<luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double num)
{
    return kayttotili.deposit(num);
}

bool Asiakas::nosto(double num)
{
    return kayttotili.withdraw(num);
}

bool Asiakas::luotonMaksu(double num)
{
    return luottotili.deposit(num);
}

bool Asiakas::luotonNosto(double num)
{
    return luottotili.withdraw(num);
}

bool Asiakas::tiliSiirto(double num, Asiakas & saaja)
{
    cout<<getNimi()<<endl;
    showSaldo();
    cout<<"Pankkitili: "<<getNimi()<<" siirtaa "<<num<<" "<<saaja.getNimi()<<":lle."<<endl;
    cout<<getNimi()<<" ";
    if(kayttotili.withdraw(num)==false){
        return false;
    }
    cout<<saaja.getNimi()<<" ";
    if(saaja.kayttotili.deposit(num)==false){
        cout<<"VIRHE: Rahojen siirto epaonnistui. Palautetaan rahat."<<endl;
        kayttotili.deposit(num);
        return false;
    }
    cout<<saaja.getNimi()<<endl;
    saaja.showSaldo();
    return true;
}
