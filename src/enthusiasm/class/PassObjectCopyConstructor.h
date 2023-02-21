//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_PASSOBJECTCOPYCONSTRUCTOR_H
#define FIRSTCPP_PASSOBJECTCOPYCONSTRUCTOR_H
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

    void showSimpleData(){
        std::cout<<"num: "<<num<<std::endl;
    }
};

void simpleFuncObject(SoSimple obj){
    obj.showSimpleData();
}
#endif //FIRSTCPP_PASSOBJECTCOPYCONSTRUCTOR_H
