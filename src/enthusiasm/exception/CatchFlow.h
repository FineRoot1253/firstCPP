#ifndef FIRSTCPP_CATCHFLOW _H
#define FIRSTCPP_CATCHFLOW _H
#include <iostream>

class ExceptionAAA{
public:
    void showYourSelf(){
        std::cout<<"ExceptionAAA!!!"<<std::endl;
    }
};

class ExceptionBBB : public ExceptionAAA {
public:
    void showYourSelf(){
        std::cout<<"ExceptionBBB!!!"<<std::endl;
    }
};

class ExceptionCCC : public ExceptionBBB {
public:
    void showYourSelf(){
        std::cout<<"ExceptionCCC!!!"<<std::endl;
    }
};

void exceptionGenerator(int ex) noexcept(false) {
    switch(ex){
        case 1:
            throw ExceptionAAA();
        case 2:
            throw ExceptionBBB();
        default:
            throw ExceptionCCC();
    }
}
#endif // FIRSTCPP_CATCHFLOW _H

