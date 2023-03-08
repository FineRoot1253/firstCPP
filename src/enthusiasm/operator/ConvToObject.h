#ifndef FIRSTCPP_CONVTOOBJECT _H
#define FIRSTCPP_CONVTOOBJECT _H
#include <iostream>

class Number{
private:
    int num;
public:
    Number(int num = 0) : num(num){
        std::cout<<"Number(int num = 0)"<<std::endl;
    }

    Number& operator=(const Number& ref){
        std::cout<<"operator=()"<<std::endl;
        num = ref.num;
        return *this;
    }

    void showNumber(){
        std::cout<<num<<std::endl;
    }
};
#endif // FIRSTCPP_CONVTOOBJECT _H

