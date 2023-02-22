//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_CONSTOVERLOADING_H
#define FIRSTCPP_CONSTOVERLOADING_H
#include <iostream>

class SoSimple{
private:
    int num;
public:
    SoSimple(int n):num(n){
    };

    SoSimple& addNum(int n){
        num += n;
        return *this;
    }

    void simpleFunc() {
        std::cout<<"simpleFunc: "<<num<<std::endl;
    }

    void simpleFunc() const {
        std::cout<<"const simpleFunc: "<<num<<std::endl;
    }
};

void yourFunc(const SoSimple& obj){
    obj.simpleFunc();
}
#endif //FIRSTCPP_CONSTOVERLOADING_H
