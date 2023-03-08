#include "enthusiasm/operator/Functor.h"

int main(){
    Adder adder;
    std::cout<<adder(1, 3)<<std::endl;
    std::cout<<adder(1.5, 3.7)<<std::endl;
    std::cout<<adder(Point(3, 4), Point(7, 9))<<std::endl;
    return 0;
}


