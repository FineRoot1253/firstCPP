//
// Created by 홍준근 on 2023/01/16.
//
#include "enthusiasm/class/PrivateConstructor.h"

int main(){
    PrivateConstructor &constructor = PrivateConstructor::createPrivateConstructor(3);
    constructor.showNum();
    return 0;
}