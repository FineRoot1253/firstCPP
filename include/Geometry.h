//
// Created by 홍준근 on 2022/12/25.
//
#include "Point.h"
#include "DynamicArray.h"
#include "Line.h"

#ifndef FIRSTCPP_GEOMETRY_H
#define FIRSTCPP_GEOMETRY_H
class Geometry {
private:
    Point *pointArray[100];
    DynamicArray<Point>* meetPoints;
    DynamicArray<Line>* lineArray;
    int pointCounts;

    bool hasComparePoints(int currentIdx);

    int countMeetPoints();
    void compareLine(int startIndex);

public:
    Geometry();
    Geometry(Point** points, int length);
    ~Geometry();

    void addPoint(Point point);
    int getPointCounts();

    double* printDistance();
    void printDirectMeets();

};
#endif //FIRSTCPP_GEOMETRY_H
