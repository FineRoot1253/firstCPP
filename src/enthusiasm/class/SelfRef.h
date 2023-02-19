//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_SELFREF_H
#define FIRSTCPP_SELFREF_H

#include <iostream>

class SelfRef {
private:
    int num;
public:
    SelfRef(int n);
    SelfRef& adder(int n);
    SelfRef& showTwoNumber();
};


#endif //FIRSTCPP_SELFREF_H
