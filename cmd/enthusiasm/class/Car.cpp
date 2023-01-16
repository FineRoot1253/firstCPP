//
// Created by 홍준근 on 2023/01/15.
//
#include "enthusiasm/class/Car.h"

int main() {
    Car run99 = Car();
    run99.init("run99", 100);
    run99.accelerate();
    run99.accelerate();
    run99.showCarState();
    run99.breaking();
    run99.showCarState();

    Car speed77 = Car();
    speed77.init("speed77", 100);
    speed77.accelerate();
    speed77.breaking();
    speed77.showCarState();
    return 0;
}