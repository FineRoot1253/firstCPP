#ifndef FIRSTCPP_RECURSIVEFUNC _H
#define FIRSTCPP_RECURSIVEFUNC _H

#include <iostream>

void recursive(int num){
    if(num <= 0){
        return;
    }
    std::cout<<"Recursive Call! "<<num<<std::endl;
    recursive(--num);
}
#endif // FIRSTCPP_RECURSIVEFUNC _H

