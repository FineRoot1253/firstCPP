//
// Created by 홍준근 on 2023/02/21.
//
#include "enthusiasm/friend/ConstOverloading.h"

int main(){
    SoSimple obj1(2);
    const SoSimple obj2(7);
    obj1.simpleFunc();
    obj2.simpleFunc();

    yourFunc(obj1);
    yourFunc(obj2);
    return 0;
}