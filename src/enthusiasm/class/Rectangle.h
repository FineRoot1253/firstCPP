//
// Created by 홍준근 on 2023/01/15.
//

#ifndef FIRSTCPP_RECTANGLE_H
#define FIRSTCPP_RECTANGLE_H

#include "Point.h"
#include <iostream>

class Rectangle {
private:
    Point highLeft;
    Point lowRight;
public:
    Rectangle(const int &xpos1, const int &ypos1, const int &xpos2, const int &ypos2);

    void showRecInfo();
};

#endif //FIRSTCPP_RECTANGLE_H
