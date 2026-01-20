#include <iostream>
#include "son.h"
using namespace std;

int main()
{
    Son poika("Teppo","Matti");
    poika.printFatherName();
    poika.printEducation();
    poika.Father::printEducation();
    return 0;
}
