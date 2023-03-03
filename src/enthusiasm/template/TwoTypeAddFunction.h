#ifndef FIRSTCPP_TWOTYPEADDFUNCTION _H
#define FIRSTCPP_TWOTYPEADDFUNCTION _H
#include <iostream>

template<class T>
T add(T num1, T num2){
    std::cout<<"T add(T num1, T num2)"<<std::endl;
    return num1 + num2;
}

int add(int num1, int num2){
    std::cout<<"int add(int num1, int num2)"<<std::endl;
    return num1 + num2;
}

double add(double num1, double num2){
    std::cout<<"double add(double num1, double num2)"<<std::endl;
    return num1 + num2;
}
#endif // FIRSTCPP_TWOTYPEADDFUNCTION _H

