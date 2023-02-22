//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_CONSTOBJECT_H
#define FIRSTCPP_CONSTOBJECT_H
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

    void showData() const {
        std::cout<<"num: "<<num<<std::endl;
    }
};
#endif //FIRSTCPP_CONSTOBJECT_H
