//
// Created by 홍준근 on 2023/02/21.
//
#include "enthusiasm/class/ReturnObjectDeadTime.h"

int main(){
    SoSimple obj(7);
    simpleFuncObject(obj);

    std::cout<<std::endl;

    SoSimple tempRef = simpleFuncObject(obj);
    std::cout<<"Return Obj "<<&tempRef<<std::endl;
    return 0;
}