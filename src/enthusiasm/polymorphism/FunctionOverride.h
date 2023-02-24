#ifndef FIRSTCPP_FUNCTIONOVERRIDE _H
#define FIRSTCPP_FUNCTIONOVERRIDE _H
#include <cstring>
#include <iostream>

class First {
public:
    void func() {
        std::cout << "First.func" << std::endl;
    }
};

class Second : public First {
public:
    void func() {
        std::cout << "Second.func" << std::endl;
    }
};

class Third : public Second {
public:
    void func() {
        std::cout << "Third.func" << std::endl;
    }
};
#endif // FIRSTCPP_FUNCTIONOVERRIDE _H

