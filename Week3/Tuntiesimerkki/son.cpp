#include "son.h"
#include <iostream>

Son::Son(string isa, string poika) : Father(isa){
    //Isä pitää olla olemassa jo nyt!!
    SonName=poika;
    std::cout<<"Son = "<<SonName
            <<" created."<<std::endl;
    this->FatherNickName="Isukki";
}

Son::~Son(){
    std::cout<<"Son = "<<SonName
            <<" deleted."<<std::endl;
}

void Son::printEducation(){
    std::cout<<"Son education = koodari."<<std::endl;
}
