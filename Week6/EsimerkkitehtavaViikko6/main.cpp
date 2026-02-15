#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<Student> Luokka;
    Luokka.reserve(10);
    Luokka.emplace_back(Student("Saku Sammakko",1));
    Luokka.emplace_back("Jeppe Niilonpoika",2);
    Luokka.emplace_back("Aku Ankka",3);
    vector<Student>::iterator iteraattori = Luokka.begin();
    int luku = 5;
    auto sortFKT = [&](Student & a,Student & b){return a.getNumber()-luku>b.getNumber();};
    for(Student & s : Luokka){
        cout<<"Student = "<<s.getName()<<endl;
    }
    //sort(Luokka.begin(),Luokka.end(),[](Student & a,Student & b){return a.getNumber()>b.getNumber();});
    sort(Luokka.begin(),Luokka.end(),sortFKT);
    for(Student & s : Luokka){
        cout<<"Student = "<<s.getName()<<endl;
    }
    cout<<"Luokan ensimmäinen opiskelija = "<<iteraattori++->getName()<<endl;
    cout<<"Luokan toinen opiskelija = "<<iteraattori++->getName()<<endl;
    cout<<"Luokan kolmas opiskelija = "<<iteraattori->getName()<<endl;
    return 0;
}
