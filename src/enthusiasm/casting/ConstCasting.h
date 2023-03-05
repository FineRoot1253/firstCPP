#ifndef FIRSTCPP_CONSTCASTING _H
#define FIRSTCPP_CONSTCASTING _H
#include <iostream>

void showString(char* str){
    std::cout<<str<<std::endl;
}

void showAddResult(int& num1, int& num2){
    std::cout<<num1 + num2<<std::endl;
}
#endif // FIRSTCPP_CONSTCASTING _H