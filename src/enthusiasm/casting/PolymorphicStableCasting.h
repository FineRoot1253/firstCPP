#ifndef FIRSTCPP_POLYMORPHICSTABLECASTING_H
#define FIRSTCPP_POLYMORPHICSTABLECASTING_H
#include <iostream>

class SoSimple{
public:
    virtual void showSimpleInfo(){
        std::cout<<"SoSimple Base Class"<<std::endl;
    }
};

class SoComplex : public SoSimple{
public:
    void showSimpleInfo() override {
        std::cout<<"SoComplex Derived Class"<<std::endl;
    }
};
#endif // FIRSTCPP_POLYMORPHICSTABLECASTING_H

