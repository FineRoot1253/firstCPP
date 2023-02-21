//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_IKNOWTEMPOBJECT_H
#define FIRSTCPP_IKNOWTEMPOBJECT_H
#include <iostream>

class Temporary{
private:
    int num;
public:
    Temporary(int n):num(n){
        std::cout<<"create object"<<std::endl;
    };
    ~Temporary(){
        std::cout<<"destory object"<<std::endl;
    }

    void showTempInfo(){
        std::cout<<"My num is "<<num<<std::endl;
    }
};

#endif //FIRSTCPP_IKNOWTEMPOBJECT_H
