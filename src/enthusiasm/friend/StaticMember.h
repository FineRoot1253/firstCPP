#ifndef FIRSTCPP_STATICMEMBER _H
#define FIRSTCPP_STATICMEMBER _H
#include <iostream>

class SoSimple{
    static int simpleObjectCount;
public:
    SoSimple(){
        ++simpleObjectCount;
        std::cout<<simpleObjectCount<<"번째 SoSimple 객체"<<std::endl;
    }
};
int SoSimple::simpleObjectCount=0;

class SoComplex{
    static int complexObjectCount;
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

int SoComplex::complexObjectCount = 0;
#endif // FIRSTCPP_STATICMEMBER _H

