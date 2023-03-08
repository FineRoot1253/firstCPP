#ifndef FIRSTCPP_FUNCTIONVIRTUALOVERRIDE _H
#define FIRSTCPP_FUNCTIONVIRTUALOVERRIDE _H
#include <cstring>
#include <iostream>

class First {
public:
    virtual void func() {
        std::cout << "First.func" << std::endl;
    }
};

class Second : public First {
public:
    virtual void func() {
        std::cout << "Second.func" << std::endl;
    }
};

class Third : public Second {
public:
    virtual void func() {
        std::cout << "Third.func" << std::endl;
    }
};
#endif // FIRSTCPP_FUNCTIONVIRTUALOVERRIDE _H

