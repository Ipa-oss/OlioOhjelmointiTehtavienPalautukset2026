#include "lcd.h"
#include <iostream>

void LCD::begin()
{
    std::cout<<"LCD begin() called."<<std::endl;

}

void LCD::print(string s)
{
    std::cout<<"Lämpötila = "<<s<<std::endl;
}

string LCD::floatToString(float luku)
{
    text = std::to_string(luku);
    return text;
}
