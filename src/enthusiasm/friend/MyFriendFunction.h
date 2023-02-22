
#ifndef FIRSTCPP_MYFRIENDFUNCTION _H
#define FIRSTCPP_MYFRIENDFUNCTION _H

#include <iostream>

class Point;

class PointOperation {
private:
    int operationCount;
public:
    PointOperation()
            : operationCount(0) {};

    ~PointOperation() {
        std::cout << "Operation times: " << operationCount << std::endl;
    }

    Point addPoint(const Point &, const Point &);

    Point subPoint(const Point &, const Point &);
};

class Point {
private:
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos)
            : x(xpos), y(ypos) {};

    friend Point PointOperation::addPoint(const Point &, const Point &);

    friend Point PointOperation::subPoint(const Point &, const Point &);

    friend void showPointPos(const Point &);
};

Point PointOperation::addPoint(const Point &pos1, const Point &pos2) {
    ++operationCount;
    return Point(pos1.x + pos2.x, pos1.y + pos2.y);
}

Point PointOperation::subPoint(const Point &pos1, const Point &pos2) {
    ++operationCount;
    return Point(pos1.x - pos2.x, pos1.y - pos2.y);
}

void showPointPos(const Point &pos) {
    std::cout << "X: " << pos.x << ", Y: " << pos.y << std::endl;
}

#endif // FIRSTCPP_MYFRIENDFUNCTION _H

