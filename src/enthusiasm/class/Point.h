//
// Created by 홍준근 on 2023/01/15.
//

#ifndef FIRSTCPP_POINT_H
#define FIRSTCPP_POINT_H

#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int xpos, int ypos);
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};


#endif //FIRSTCPP_POINT_H
