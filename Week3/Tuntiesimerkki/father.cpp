#include "father.h"
#include <iostream>

Father::Father(string s){
    FatherName = s;
    std::cout<<"Father = "<<FatherName
            <<" created."<<std::endl;
}

Father::~Father(){
    std::cout<<"Father = "<<FatherName
            <<" deleted."<<std::endl;
}

void Father::printFatherName(){
    std::cout<<"Father name = "<<FatherName<<std::endl;
    std::cout<<"Father nickname = "<<FatherNickName<<std::endl;
}

void Father::printEducation(){
    std::cout<<"Father education = puuseppä."<<std::endl;
}
