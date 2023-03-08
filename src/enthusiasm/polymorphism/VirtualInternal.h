#ifndef FIRSTCPP_VITUALINTERNAL _H
#define FIRSTCPP_VITUALINTERNAL _H
#include <iostream>

class Fruit{
private:
    int num1;
public:
    virtual void func1(){
        std::cout<<"func1"<<std::endl;
    }

    virtual void func2(){
        std::cout<<"func2"<<std::endl;
    }
};

class Apple: Fruit{
private:
    int num2;
public:
    void func1() override{
        std::cout<<"Apple.func1()"<<std::endl;
    }
    void func3(){
        std::cout<<"func3"<<std::endl;
    }
};
#endif // FIRSTCPP_VITUALINTERNAL _H

