//
// Created by 홍준근 on 2023/01/13.
//

#ifndef FIRSTCPP_RACINGCAR_H
#define FIRSTCPP_RACINGCAR_H

#include <iostream>

namespace CAR_CONSTANTS {
    enum {
        ID_LENGTH = 20,
        MAX_SPEED = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}


struct RacingCar {
    char gamerID[CAR_CONSTANTS::ID_LENGTH];
    int fuelGauge;
    int currentSpeed;
    void showCarState();
    void accelerate();
    void breaking();
};


#endif //FIRSTCPP_RACINGCAR_H
