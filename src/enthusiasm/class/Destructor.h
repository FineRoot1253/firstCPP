//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_DESTRUCTOR_H
#define FIRSTCPP_DESTRUCTOR_H

#include <iostream>

class Person {
private:
    char *name;
    int age;
public:
    Person(char *myName, int myAge);

    void showPersonInfo() const ;
    ~Person();
};


#endif //FIRSTCPP_DESTRUCTOR_H
