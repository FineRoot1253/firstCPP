//
// Created by 홍준근 on 2023/02/23.
//
#include "enthusiasm/template/PointTemplate.h"

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y){}

template <class T>
void Point<T>::showPosition() const {
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}