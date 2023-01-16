//
// Created by 홍준근 on 2023/01/13.
//

#include "RacingCar.h"

void RacingCar::showCarState() {
    std::cout<<"소유자 ID: " << gamerID<< std::endl;
    std::cout<<"연료량: " << fuelGauge<< std::endl;
    std::cout<<"현재속도: " << currentSpeed<< std::endl<<std::endl;
}

void RacingCar::accelerate() {
    if (fuelGauge <= 0) {
        return;
    } else {
        fuelGauge -= CAR_CONSTANTS::FUEL_STEP;
    }
    if (currentSpeed + CAR_CONSTANTS::ACC_STEP >= CAR_CONSTANTS::MAX_SPEED) {
        currentSpeed = CAR_CONSTANTS::MAX_SPEED;
        return;
    }
    currentSpeed += CAR_CONSTANTS::ACC_STEP;
}

void RacingCar::breaking() {
    if (currentSpeed < CAR_CONSTANTS::BRK_STEP) {
        currentSpeed = 0;
        return;
    }
    currentSpeed -= CAR_CONSTANTS::BRK_STEP;
}