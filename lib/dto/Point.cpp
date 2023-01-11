//
// Created by 홍준근 on 2022/12/25.
//
#include "Point.h"
#include <cmath>

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(double posX, double posY) {
    this->x = posX;
    this->y = posY;
}

Point* Point::copyOf(Point *point) {
    return new Point(point->getX(), point->getY());
}

bool Point::isEqual(Point *point) {
    if (this->x == point->getX() && this->y == point->getY()) {
        return true;
    }
    return false;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}

double Point::getDiffDistance(const Point point) {
    return sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2));
}