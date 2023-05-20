//
// Created by 홍준근 on 2023/03/18.
//

#ifndef FIRSTCPP_POINT_H
#define FIRSTCPP_POINT_H

#include <iostream>

class Point {
private:
    int xpos;
    int ypos;

    bool isXposEqual(const Point& target);

    bool isYposEqual(const Point& target);
public:
    Point():xpos(0), ypos(0){};
    Point(const int &xpos, const int &ypos);

    Point(const Point &ref);

    Point &operator=(const Point &ref) ;

    int getXpos() const;
    int getYpos() const;

    void showPointPosition() const ;

    int compareWith(const Point& target);


};


#endif //FIRSTCPP_POINT_H
