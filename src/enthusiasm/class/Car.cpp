//
// Created by 홍준근 on 2023/01/13.
//

#include "Car.h"

void Car::init(char *id, int fuel) {
    strcpy(gamerID, id);
    fuelGauge=fuel;
    currentSpeed = 0;
}

void Car::showCarState() {
    std::cout<<"소유자 ID: " << gamerID<< std::endl;
    std::cout<<"연료량: " << fuelGauge<< std::endl;
    std::cout<<"현재속도: " << currentSpeed<< std::endl<<std::endl;
}

void Car::accelerate() {
    if (fuelGauge <= 0) {
        return;
    } else {
        fuelGauge -= car_constants::FUEL_STEP;
    }
    if (currentSpeed + car_constants::ACC_STEP >= car_constants::MAX_SPEED) {
        currentSpeed = car_constants::MAX_SPEED;
        return;
    }
    currentSpeed += car_constants::ACC_STEP;
}

void Car::breaking() {
    if (currentSpeed < car_constants::BRK_STEP) {
        currentSpeed = 0;
        return;
    }
    currentSpeed -= car_constants::BRK_STEP;
}

