//
// Created by 홍준근 on 2023/01/15.
//
#include "enthusiasm/struct/RacingCar.h"

int main() {
    RacingCar run99 = {"run99", 100, 0};
    run99.accelerate();
    run99.accelerate();
    run99.showCarState();
    run99.breaking();
    run99.showCarState();

    RacingCar speed77 = {"speed77", 100, 0};
    speed77.accelerate();
    speed77.breaking();
    speed77.showCarState();
    return 0;
}