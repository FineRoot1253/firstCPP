//
// Created by 홍준근 on 2022/12/25.
//

#include "../../include/Line.h"

Line::Line() {
    this->beginPoint = new Point();
    this->endPoint = new Point();
}

Line::Line(Point* beginPoint, Point* endPoint) {
    Point * tempBeginPoint = this->beginPoint;
    Point * tempEndPoint = this->endPoint;
    this->beginPoint = beginPoint;
    this->endPoint = endPoint;
    delete tempBeginPoint;
    delete tempEndPoint;
}

Line::~Line() {
    delete beginPoint;
    delete endPoint;
}

bool Line::isEqual(Line line) {
    return line.beginPoint->isEqual(beginPoint) && line.endPoint->isEqual(beginPoint);
}

double Line::getSlope(){
    int y = endPoint->getY() - beginPoint->getY();
    int x = endPoint->getX() - beginPoint->getX();
    if (x == 0) {
        return 0;
    }
    if (y == 0) {
        return 1;
    }
    return y / x; // 기울기
}

double Line::getIntercept() {
    return beginPoint->getX() * getSlope() + (-1 * beginPoint->getY());
}

Point Line::getBeginPoint() {
    return *beginPoint;
}

Point Line::getEndPoint() {
    return *endPoint;
}

Point* Line::getAll() {
    return new Point[2]{*beginPoint, *endPoint};
}
