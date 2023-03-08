#ifndef FIRSTCPP_POINTCLASSTEMPLATEFUNCDEF _H
#define FIRSTCPP_POINTCLASSTEMPLATEFUNCDEF _H
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

template <class T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y){}

template <class T>
void Point<T>::showPosition() const {
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}

#endif // FIRSTCPP_POINTCLASSTEMPLATEFUNCDEF _H

