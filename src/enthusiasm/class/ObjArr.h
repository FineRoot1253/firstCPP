//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_OBJARR_H
#define FIRSTCPP_OBJARR_H

#include <iostream>

class Person {
private:
    char *name;
    int age;
public:
    Person(char *myName, int myAge);
    Person();
    void setPersonInfo(char *myName, int myAge);
    void showPersonInfo() const ;
    ~Person();
};


#endif //FIRSTCPP_OBJARR_H
