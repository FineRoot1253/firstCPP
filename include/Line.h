//
// Created by 홍준근 on 2022/12/25.
//
#include "Point.h"

#ifndef FIRSTCPP_LINE_H
#define FIRSTCPP_LINE_H

class Line {
private:
    Point* beginPoint;
    Point* endPoint;
public:
    Line();
    Line(Point* beginPoint, Point* endPoint);
    ~Line();

    bool isEqual(Line line);
    double getSlope();
    double getIntercept();
    Point getBeginPoint();
    Point getEndPoint();
    Point* getAll();

};

#endif //FIRSTCPP_LINE_H
