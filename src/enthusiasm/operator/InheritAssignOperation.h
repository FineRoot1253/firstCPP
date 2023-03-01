#ifndef FIRSTCPP_INHERITASSIGNOPERATION _H
#define FIRSTCPP_INHERITASSIGNOPERATION _H
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

    First& operator=(const First& ref){
        std::cout<<"First& operator=()"<<std::endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First{
private:
    int num3;
    int num4;
public:
    Second(int num1= 0, int num2= 0, int num3= 0, int num4= 0): First(num1, num2),num3(num3), num4(num4){}

    void showData() const {
        First::showData();
        std::cout<<"["<<num3<<", "<<num4<<"]"<<std::endl;
    }

//    Second& operator=(const Second& ref){
//        std::cout<<"Second& operator=()"<<std::endl;
//        num3 = ref.num3;
//        num4 = ref.num4;
//        return *this;
//    }
};
#endif // FIRSTCPP_INHERITASSIGNOPERATION _H

