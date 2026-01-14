#include "dht.h"
#include <iostream>
#include <ctime>

void DHT::begin()
{
    std::cout<<"DHT begin() called."<<std::endl;
    gen.setSeed(time(NULL));
    std::cout<<"Random seed set."<<std::endl;
}

float DHT::readTemperature()
{
    long long temp = gen.rand();
    temp = (temp % 20) + 10;
    temperature = (float)temp;
    return temperature;// Expects float
}
