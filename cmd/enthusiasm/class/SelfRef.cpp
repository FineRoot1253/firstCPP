//
// Created by 홍준근 on 2023/01/16.
//
#include "enthusiasm/class/SelfRef.h"

int main(){
    SelfRef obj(3);
    SelfRef &ref = obj.adder(2);

    obj.showTwoNumber();
    ref.showTwoNumber();

    ref.adder(1).showTwoNumber().adder(2).showTwoNumber();
    return 0;
}