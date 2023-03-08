#include "enthusiasm/polymorphism/MultiInheri3.h"

int main(){
    std::cout<<"객체 생성 전 ....."<<std::endl;
    LastDerived lastDerived;
    std::cout<<"객체 생성 후 ....."<<std::endl;
    lastDerived.complexFunc();
    return 0;
}