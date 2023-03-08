#ifndef FIRSTCPP_MULTIINHERI2 _H
#define FIRSTCPP_MULTIINHERI2 _H
#include <iostream>

class BaseOne{
public:
    void simpleFunc(){
        std::cout<<"BaseOne"<<std::endl;
    }
};

class BaseTwo{
public:
    void simpleFunc(){
        std::cout<<"BaseTwo"<<std::endl;
    }
};

class MultiDerived: public BaseOne, protected BaseTwo{
public:
    void complexFunc(){
        BaseOne::simpleFunc();
        BaseTwo::simpleFunc();
    }
};
#endif // FIRSTCPP_MULTIINHERI2 _H

