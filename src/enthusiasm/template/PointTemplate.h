//
// Created by 홍준근 on 2023/02/23.
//

#ifndef FIRSTCPP_POINTTEMPLATE_H
#define FIRSTCPP_POINTTEMPLATE_H
#include <iostream>

template <class T>
class Point{
private:
    T xpos;
    T ypos;
public:
    Point(T x= 0, T y= 0);

    void showPosition() const ;
};

#endif //FIRSTCPP_POINTTEMPLATE_H
