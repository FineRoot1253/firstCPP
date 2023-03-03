#ifndef FIRSTCPP_POINT _H
#define FIRSTCPP_POINT _H

#include "enthusiasm/template/ArrayTemplate.h"

template <class T>
class Point{
private:
    T xpos;
    T ypos;
public:
    Point(T x= 0, T y= 0);

    void showPosition() const;
};
#endif // FIRSTCPP_POINT _H

