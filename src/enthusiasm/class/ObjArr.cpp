//
// Created by 홍준근 on 2023/01/16.
//

#include "ObjArr.h"

Person::Person(char *myName, int myAge) {
    int len = strlen(myName) + 1;
    name = new char[len];
    strcpy(name, myName);
    age = myAge;
}

Person::Person() {
    name = nullptr;
    age=0;
    std::cout<<"called Person()"<<std::endl;
}

void Person::setPersonInfo(char *myName, int myAge) {
    name = myName;
    age = myAge;
}

void Person::showPersonInfo() const {
    std::cout << "이름: " << name << std::endl;
    std::cout << "나이: " << age << std::endl;
}
Person::~Person(){
    delete []name;
    std::cout<<"called destructor!"<<std::endl;
}
