#ifndef FIRSTCPP_NEEDGLOBAL _H
#define FIRSTCPP_NEEDGLOBAL _H
#include <iostream>

int simpleObjectCount = 0;
int complexObjectCount = 0;

class SoSimple{
public:
    SoSimple(){
        ++simpleObjectCount;
        std::cout<<simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    }
};

class SoComplex{
public:
    SoComplex(){
        ++complexObjectCount;
        std::cout<<complexObjectCount<<"번째 SoComplex 객체"<<std::endl;
    }

    SoComplex(const SoComplex& copy){
        ++complexObjectCount;
        std::cout<<complexObjectCount<<"번째 SoComplex 객체"<<std::endl;
    }
};
#endif // FIRSTCPP_NEEDGLOBAL _H

