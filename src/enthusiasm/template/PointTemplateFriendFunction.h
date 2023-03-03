#ifndef FIRSTCPP_POINTTEMPLATEFRIENDFUNCTION _H
#define FIRSTCPP_POINTTEMPLATEFRIENDFUNCTION _H

#include <iostream>

template<class T>
class Point {
private:
    T xpos;
    T ypos;
public:
    Point(T x = 0, T y = 0);

    friend Point<int> operator+(const Point<int> &point1, const Point<int> &point2);

    friend std::ostream &operator<<(std::ostream &, const Point<int> &);
};

template<class T>
Point<T>::Point(T x, T y)
        :xpos(x), ypos(y) {}

Point<int> operator+(const Point<int> &point1, const Point<int> &point2) {
    return Point<int>(point1.xpos + point2.xpos, point1.ypos + point2.ypos);
}

std::ostream &operator<<(std::ostream &output, const Point<int> &ref) {
    output << "[" << ref.xpos << ", " << ref.ypos << "]" << std::endl;
    return output;
}

#endif // FIRSTCPP_POINTTEMPLATEFRIENDFUNCTION _H

