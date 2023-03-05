#ifndef FIRSTCPP_PASSEXCEPTION _H
#define FIRSTCPP_PASSEXCEPTION _H
#include <iostream>

void divide(int num1, int num2){
    if(num2 == 0){
        throw num2;
    }
    std::cout<<"나눗셈의 몫: "<<num1/num2<<std::endl;
    std::cout<<"나눗셈의 나머지: "<<num1%num2<<std::endl;
}
#endif // FIRSTCPP_PASSEXCEPTION _H

