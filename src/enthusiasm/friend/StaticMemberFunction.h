#ifndef FIRSTCPP_STATICMEMBERFUNCTION _H
#define FIRSTCPP_STATICMEMBERFUNCTION _H
#include <iostream>

class SoSimple{
public:
    int num1;
    static int num2;
public:
    SoSimple(int n):num1(n){
    }
    static void add(int n){
//        num1+=n;  // ERROR!
        num2+=n;
    }
};
int SoSimple::num2 = 0;
#endif // FIRSTCPP_STATICMEMBERFUNCTION _H

