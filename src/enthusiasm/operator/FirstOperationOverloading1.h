#ifndef FIRSTCPP_FIRSTOPERATIONOVERLOADING1 _H
#define FIRSTCPP_FIRSTOPERATIONOVERLOADING1 _H
#include <iostream>

class First{
private:
    int num1;
    int num2;
public:
    First(int num1= 0, int num2= 0):num1(num1), num2(num2){}

    void showData() const {
        std::cout<<"["<<num1<<", "<<num2<<"]"<<std::endl;
    }
};

class Second{
private:
    int num3;
    int num4;
public:
    Second(int num3= 0, int num4= 0):num3(num3), num4(num4){}

    void showData() const {
        std::cout<<"["<<num3<<", "<<num4<<"]"<<std::endl;
    }

    Second& operator=(const Second& ref){
        std::cout<<"Second& operator="<<std::endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
};
#endif // FIRSTCPP_FIRSTOPERATIONOVERLOADING1 _H

