//
// Created by 홍준근 on 2023/02/21.
//

#ifndef FIRSTCPP_RETURNOBJECTDEADTIME_H
#define FIRSTCPP_RETURNOBJECTDEADTIME_H

#include <iostream>

class SoSimple {
private:
    int num;
public:
    SoSimple(int n)
            : num(n) {
        std::cout << "New Object: " << this << std::endl;
    };

    SoSimple(const SoSimple &copy)
            : num(copy.num) {
        std::cout << "New Copy Object:" << this << std::endl;
    };

    ~SoSimple() {
        std::cout << "Destroy Object: " << this << std::endl;
    }
};

SoSimple simpleFuncObject(SoSimple obj) {
    std::cout << "Parm ADDRESS: " << &obj << std::endl;
    return obj;
}

#endif //FIRSTCPP_RETURNOBJECTDEADTIME_H
