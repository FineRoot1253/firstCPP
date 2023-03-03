#ifndef FIRSTCPP_POINTCLASSTEMPLATE _H
#define FIRSTCPP_POINTCLASSTEMPLATE _H
#include <iostream>

template <class T>
class Point{
private:
    T xpos;
    T ypos;
public:
    Point(T x= 0, T y= 0):xpos(x), ypos(y){}

    void showPosition() const {
        std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
    }
    Point operator*(int times){
        Point pos(xpos * times, ypos * times);
        return pos;
    }
};
#endif // FIRSTCPP_POINTCLASSTEMPLATE _H

