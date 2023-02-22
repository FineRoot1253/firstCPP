#ifndef FIRSTCPP_MUTABLE _H
#define FIRSTCPP_MUTABLE _H
#include <iostream>

class SoSimple{
public:
    int num1;
    mutable int num2;
public:
    SoSimple(int num1, int num2):num1(num1), num2(num2){
    }
    void showSimpleData() const{
        std::cout<<num1<<", "<<num2<<std::endl;
    }

    void copyToNum2() const{
        num2=num1;
    }
};
#endif // FIRSTCPP_MUTABLE _H

