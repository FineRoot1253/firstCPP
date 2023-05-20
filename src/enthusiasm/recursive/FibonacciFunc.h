#ifndef FIRSTCPP_FIBONACCIFUNC _H
#define FIRSTCPP_FIBONACCIFUNC _H
#include <iostream>

int fibo(int num){

    std::cout<<"func call Param "<<num<<" "<<std::endl;

    if(num == 1){
        return 0;
    }else if(num == 2){
        return 1;
    }else{
        return fibo(num - 1) + fibo(num - 2);
    }
}
#endif // FIRSTCPP_FIBONACCIFUNC _H

