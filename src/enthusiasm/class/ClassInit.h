//
// Created by 홍준근 on 2023/02/19.
//

#ifndef FIRSTCPP_CLASSINIT_H
#define FIRSTCPP_CLASSINIT_H
#include <iostream>
class SoSimple{
private:
    int num1;
    int num2;
public:
    SoSimple(int n1, int n2):num1(n1), num2(n2){
    };
    SoSimple(SoSimple& copy):num1(copy.num1),num2(copy.num2){
        std::cout<<"Called SoSimple(SoSimple &copy)"<<std::endl;
    };

    void showSimpleData(){
        std::cout<<num1<<std::endl;
        std::cout<<num2<<std::endl;
    }
};
#endif //FIRSTCPP_CLASSINIT_H
