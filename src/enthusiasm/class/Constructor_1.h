//
// Created by 홍준근 on 2023/01/16.
//

#ifndef FIRSTCPP_CONSTRUCTOR_1_H
#define FIRSTCPP_CONSTRUCTOR_1_H

#include <iostream>

class SimpleClass {
private:
    int num1;
    int num2;
public:
    SimpleClass();
    SimpleClass(int n);
    SimpleClass(int num1, int num2);
    void showData() const;
};


#endif //FIRSTCPP_CONSTRUCTOR_1_H
