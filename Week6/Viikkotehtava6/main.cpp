#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"
using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:{
                cout<<"Student name?"<<endl;
                string tempName;
                cin>>tempName;
                cout<<"Student age?"<<endl;
                int tempAge;
                cin>>tempAge;
                studentList.push_back(Student(tempName,tempAge));
                break;
            }
            case 1:{
                for(auto it=studentList.begin();it!=studentList.end();it++){
                    it->printStudentInfo();
                }
                break;
            }
            case 2:{
                sort(studentList.begin(),studentList.end(),[](Student a,Student b){return a.getName()<b.getName();}); //These things fucking suck actually.
                for(auto it=studentList.begin();it!=studentList.end();it++){
                    it->printStudentInfo();
                }
                break;
            }
            case 3:{
                sort(studentList.begin(),studentList.end(),[](Student a,Student b){return a.getAge()<b.getAge();});
                for(auto it=studentList.begin();it!=studentList.end();it++){
                    it->printStudentInfo();
                }
                break;
            }
            case 4:{
                cout<<"What is the name of the student you want to find?"<<endl;
                string tempName;
                cin>>tempName;
                auto finder=find_if(studentList.begin(),studentList.end(),[tempName](Student r){return r.getName()==tempName;});
                if(finder != studentList.end()){
                    cout<<"Student found:"<<endl;
                    finder->printStudentInfo(); //This took way too long.
                }
                break;
            }
            default:{
                cout<< "Wrong selection, stopping..."<<endl;
                break;
            }
        }
    }while(selection < 5);
return 0;
}
