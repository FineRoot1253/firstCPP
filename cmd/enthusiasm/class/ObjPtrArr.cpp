//
// Created by 홍준근 on 2023/01/16.
//
#include "enthusiasm/class/ObjArr.h"

int main(){
    Person *personArr[3];
    char namestr[100];
    int age;
    for (int i = 0; i < 3; ++i) {
        std::cout<<"이름: ";
        std::cin>>namestr;
        std::cout<<"나이: ";
        std::cin>>age;
        personArr[i] = new Person(namestr, age);
    }
    personArr[0]->showPersonInfo();
    personArr[1]->showPersonInfo();
    personArr[2]->showPersonInfo();
    delete personArr[0];
    delete personArr[1];
    delete personArr[2];
    return 0;
}