//
// Created by 홍준근 on 2023/02/19.
//

#ifndef FIRSTCPP_SHALLOCOPYERROR_H
#define FIRSTCPP_SHALLOCOPYERROR_H
#include <iostream>
#include <cstring>

class Person{
private:
    char* name;
    int age;
public:
    Person(char* myName, int myAge):age(myAge){
        name = new char[std::strlen(myName)+1];
        std::strcpy(name, myName);
    }

    ~Person(){
        delete[] name;
        std::cout<<"called destructor!"<<std::endl;
    }

    void showPersonInfo() const{
        std::cout<<"이름: "<<name<<std::endl;
        std::cout<<"나이: "<<age<<std::endl;
    }
};
#endif //FIRSTCPP_SHALLOCOPYERROR_H
