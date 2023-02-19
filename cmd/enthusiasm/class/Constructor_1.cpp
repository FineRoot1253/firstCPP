//
// Created by 홍준근 on 2023/01/16.
//
#include "enthusiasm/class/Constructor_1.h"
int main(){
    SimpleClass simpleClass1;
    simpleClass1.showData();

    SimpleClass simpleClass2(100);
    simpleClass2.showData();

    SimpleClass simpleClass3(100, 200);
    simpleClass3.showData();
    return 0;
}