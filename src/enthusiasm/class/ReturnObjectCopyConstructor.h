//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_RETURNOBJECTCOPYCONSTRUCTOR_H
#define FIRSTCPP_RETURNOBJECTCOPYCONSTRUCTOR_H
#include <iostream>

class SoSimple{
private:
    int num;
public:
    SoSimple(int n):num(n){
    };
    SoSimple(const SoSimple& copy):num(copy.num){
        std::cout<<"Called SoSimple(const SoSimple &copy)"<<std::endl;
    };

    SoSimple& addNum(int n){
        num += n;
        return *this;
    }

    void showData(){
        std::cout<<"num: "<<num<<std::endl;
    }
};

SoSimple simpleFuncObject(SoSimple obj){
    std::cout<<"return 이전"<<std::endl;
    return obj;
}
#endif //FIRSTCPP_RETURNOBJECTCOPYCONSTRUCTOR_H
