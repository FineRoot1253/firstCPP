#ifndef FIRSTCPP_PROTECTEDHERI _H
#define FIRSTCPP_PROTECTEDHERI _H
#include <iostream>

class Base {
private:
    int baseNum1;
protected:
    int baseNum2;
public:
    int baseNum3;
    Base()
            : baseNum1(1), baseNum2 (2), baseNum3(4) {
    }
};

class Derived : protected Base{
};
#endif // FIRSTCPP_PROTECTEDHERI _H

