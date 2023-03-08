//
// Created by 홍준근 on 2023/01/16.
//

#include "Constructor_1.h"

SimpleClass::SimpleClass() {
    num1 = 0;
    num2 = 0;
}

SimpleClass::SimpleClass(int n) {
    num1 = n;
    num2 = 0;
}

SimpleClass::SimpleClass(int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
}

void SimpleClass::showData() const {
    std::cout<<num1<<" "<<num2<<std::endl;
}