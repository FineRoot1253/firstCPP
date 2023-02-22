//
// Created by 홍준근 on 2023/02/21.
//
#include "enthusiasm/friend/ConstObject.h"

int main(){
    const SoSimple obj(10);
    //obj.addNum(20); // ERROR!
    obj.showData();
    return 0;
}