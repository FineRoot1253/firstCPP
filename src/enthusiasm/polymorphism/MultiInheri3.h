#ifndef FIRSTCPP_MULTIINHERI3 _H
#define FIRSTCPP_MULTIINHERI3 _H
#include <iostream>

class Base{
public:
    Base(){
        std::cout<<"Base Constructor"<<std::endl;
    }
    void simpleFunc(){
        std::cout<<"Base"<<std::endl;
    }
};

class MiddleDerivedOne: virtual public Base{
public:
    MiddleDerivedOne():Base(){
        std::cout<<"MiddleDerivedOne Constructor"<<std::endl;
    }
    void middleFuncOne(){
        simpleFunc();
        std::cout<<"MiddleDerivedOne"<<std::endl;
    }
};

class MiddleDerivedTwo: virtual public Base{
public:
    MiddleDerivedTwo():Base(){
        std::cout<<"MiddleDerivedTwo Constructor"<<std::endl;
    }
    void middleFuncTwo(){
        simpleFunc();
        std::cout<<"MiddleDerivedTwo"<<std::endl;
    }
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo{
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo(){
        std::cout<<"LastDerived Constructor"<<std::endl;
    }

    void complexFunc(){
        middleFuncOne();
        middleFuncTwo();
        simpleFunc();
    }
};
#endif // FIRSTCPP_MULTIINHERI3 _H

