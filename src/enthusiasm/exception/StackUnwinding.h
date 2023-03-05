#ifndef FIRSTCPP_STACKUNWINDING _H
#define FIRSTCPP_STACKUNWINDING _H
#include <iostream>

void simpleFuncOne();
void simpleFuncTwo();
void simpleFuncThree();

void simpleFuncOne(){
    std::cout<<"simpleFuncOne()"<<std::endl;
    simpleFuncTwo();
}

void simpleFuncTwo(){
    std::cout<<"simpleFuncTwo()"<<std::endl;
    simpleFuncThree();
}

void simpleFuncThree(){
    std::cout<<"simpleFuncThree()"<<std::endl;
    throw -1;
}
#endif // FIRSTCPP_STACKUNWINDING _H

