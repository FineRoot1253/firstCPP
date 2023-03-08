#ifndef FIRSTCPP_MULTIINHERI1 _H
#define FIRSTCPP_MULTIINHERI1 _H
#include <iostream>

class BaseOne{
public:
    void simpleFuncOne(){
        std::cout<<"BaseOne"<<std::endl;
    }
};

class BaseTwo{
public:
    void simpleFuncTwo(){
        std::cout<<"BaseTwo"<<std::endl;
    }
};

class MultiDerived: public BaseOne, public BaseTwo{
public:
    void complexFunc(){
        simpleFuncOne();
        simpleFuncTwo();
    }
};
#endif // FIRSTCPP_MULTIINHERI1 _H