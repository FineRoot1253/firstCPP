#ifndef FIRSTCPP_RETHROW _H
#define FIRSTCPP_RETHROW _H
#include <iostream>

void divide(int num1, int num2){
    try{
        if(num2 == 0){
            throw num2;
        }
        std::cout<<"나눗셈의 몫: "<<num1/num2<<std::endl;
        std::cout<<"나눗셈의 나머지: "<<num1%num2<<std::endl;
    }catch(int ex){
        std::cout<<"first catch"<<std::endl;
        throw;
    }

}

#endif // FIRSTCPP_RETHROW _H

