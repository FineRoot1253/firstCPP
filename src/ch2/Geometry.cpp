//
// Created by 홍준근 on 2022/12/06.
//
#include <iostream>
#include "Geometry.h"

Geometry::Geometry() {
    pointCounts = 0;
    meetPoints = new DynamicArray<Point>();
    lineArray = new DynamicArray<Line>();
}

Geometry::Geometry(Point** points, int length) {
    std::copy(points, points + length, pointArray);
    meetPoints = new DynamicArray<Point>();
    lineArray = new DynamicArray<Line>();
    pointCounts = length;
}

Geometry::~Geometry() {
    delete lineArray;
    delete meetPoints;
    for (int i = 0; i < pointCounts; ++i) {
        delete pointArray[i];
    }
}

void Geometry::compareLine(int startIndex) {
    if(startIndex+2 < lineArray->getSize()){
        compareLine(startIndex+1);
    }
    for (int i = startIndex; i < lineArray->getSize() - 1; ++i) {
        Line *currentStandardLine = lineArray->get(i);
        Line *nextLine = lineArray->get(i+1);
        if (currentStandardLine->getSlope() != nextLine->getSlope()) {
            double meetPosX =
                    nextLine->getIntercept() - currentStandardLine->getIntercept() / currentStandardLine->getSlope() -
                    nextLine->getSlope();
            double meetPosY = currentStandardLine->getSlope() * (meetPosX) + currentStandardLine->getIntercept();
            meetPoints->add(new Point(meetPosX, meetPosY));
        }
    }
}
int Geometry::getPointCounts(){
    return this->pointCounts;
}

int Geometry::countMeetPoints() {
    if(meetPoints->getSize() > 0 || lineArray->getSize() > 0){
        meetPoints->clear();
        lineArray->clear();
    }
    int currentPosX =0;
    int maxPosX = pointCounts - 1;
    for (int i = 0; i < maxPosX; ++i) {
        for (int j = currentPosX; j < pointCounts - 1; ++j) {
            lineArray->add(new Line(new Point(pointArray[i]->getX(), pointArray[i]->getY()), new Point(pointArray[j]->getX(), pointArray[j]->getY())));
        }
        currentPosX++;
    }
    compareLine(0);
    return meetPoints->getSize();
}

void Geometry::addPoint(Point point) {
    pointArray[pointCounts++] = new Point(point.getX(), point.getY());
}

double* Geometry::printDistance() {
    int count = 0;
    double* result = new double[pointCounts * pointCounts];
    for (int i = 0; i < pointCounts; ++i) {
        for (int j = 0; j < pointCounts; ++j) {
            std::cout << "Between Point" << i + 1 << " and Point" << j + 1 << " distance: "
                      << this->pointArray[i]->getDiffDistance(*pointArray[j]) << std::endl;
            result[count++] = this->pointArray[i]->getDiffDistance(*pointArray[j]);
        }
    }
    return result;
}

void Geometry::printDirectMeets() {
    std::cout << "DirectMeets: " << countMeetPoints() << std::endl;
}