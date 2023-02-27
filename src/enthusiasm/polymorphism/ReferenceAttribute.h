#ifndef FIRSTCPP_REFERENCEATTRIBUTE _H
#define FIRSTCPP_REFERENCEATTRIBUTE _H
#include <cstring>
#include <iostream>

class First {
public:
    void firstFunc(){
        std::cout<<"firstFunc()"<<std::endl;
    }
    virtual void simpleFunc(){
        std::cout<<"First`s simpleFunc()"<<std::endl;
    }
};

class Second : public First {
public:
    void secondFunc(){
        std::cout<<"secondFunc()"<<std::endl;
    }
    virtual void simpleFunc(){
        std::cout<<"Second`s simpleFunc()"<<std::endl;
    }
};

class Third : public Second {
public:
    void thirdFunc(){
        std::cout<<"thirdFunc()"<<std::endl;
    }
    virtual void simpleFunc(){
        std::cout<<"Third`s simpleFunc()"<<std::endl;
    }
};
#endif // FIRSTCPP_REFERENCEATTRIBUTE _H

