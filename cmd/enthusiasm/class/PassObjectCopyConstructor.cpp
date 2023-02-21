//
// Created by 홍준근 on 2023/02/21.
//
#include "enthusiasm/class/PassObjectCopyConstructor.h"

int main(){
    SoSimple obj(10);
    std::cout<<"함수 호출 전"<<std::endl;
    simpleFuncObject(obj);
    std::cout<<"함수 호출 후"<<std::endl;
    return 0;
}