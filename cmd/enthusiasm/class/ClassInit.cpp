//
// Created by 홍준근 on 2023/02/19.
//
#include "enthusiasm/class/ClassInit.h"

int main() {

    SoSimple sim1(15, 30);
    std::cout<<"생성 및 초기화 직전"<<std::endl;
    SoSimple sim2 = sim1;
    std::cout<<"생성 및 초기화 직후"<<std::endl;
    sim2.showSimpleData();
    return 0;
}