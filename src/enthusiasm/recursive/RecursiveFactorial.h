#ifndef FIRSTCPP_RECURSIVEFACTORIAL _H
#define FIRSTCPP_RECURSIVEFACTORIAL _H
#include <iostream>

int factorial(int num){
    if(num == 0){
        return 1;
    }else{
        return num * factorial(--num);
    }

}
#endif // FIRSTCPP_RECURSIVEFACTORIAL _H

