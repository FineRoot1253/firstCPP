#ifndef FIRSTCPP_POINTEROPERATOROVERLOADING _H
#define FIRSTCPP_POINTEROPERATOROVERLOADING _H
#include <iostream>

class Number{
private:
    int num;
public:
    Number(int num) : num(num){}

    void showData(){
        std::cout<<num<<std::endl;
    }

    Number* operator->(){
        return this;
    }

    Number& operator*(){
        return *this;
    }
};
#endif // FIRSTCPP_POINTEROPERATOROVERLOADING _H