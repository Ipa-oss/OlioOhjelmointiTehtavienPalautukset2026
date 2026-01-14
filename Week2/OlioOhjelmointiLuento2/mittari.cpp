#include "mittari.h"
#include <iostream>

void Mittari::setup()
{
    lcdOlio.begin();
    dhtOlio.begin();
    varoitusvalo=13;
}

void Mittari::mittaus()
{
    for(int i=0;i<10;i++){
        float lampo = dhtOlio.readTemperature();
        lcdOlio.print(lcdOlio.floatToString(lampo));
        if (lampo > 20){
            std::cout << "Varoitus! Valo: " << varoitusvalo << std::endl;
        }
    }
}
