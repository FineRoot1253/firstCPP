//
// Created by 홍준근 on 2022/12/25.
//

#ifndef FIRSTCPP_POINT_H
#define FIRSTCPP_POINT_H
class Point {
private:
    double x, y;
public:
    Point();
    Point(double posX, double posY);

    Point* copyOf(Point* point);

    bool isEqual(Point *point);

    double getX();
    double getY();
    double getDiffDistance(const Point point);
};
#endif //FIRSTCPP_POINT_H
