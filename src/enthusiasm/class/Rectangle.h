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
    bool init(const Point &highLeft, const Point &lowRight);

    void showRecInfo();
};

#endif //FIRSTCPP_RECTANGLE_H
