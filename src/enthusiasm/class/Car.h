//
// Created by 홍준근 on 2023/01/13.
//

#ifndef FIRSTCPP_CAR_H
#define FIRSTCPP_CAR_H

#include <iostream>

namespace car_constants {
    enum {
        ID_LENGTH = 20,
        MAX_SPEED = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car {
private:
    char gamerID[car_constants::ID_LENGTH];
    int fuelGauge;
    int currentSpeed;
public:
    void init(char *id, int fuel);
    void showCarState();
    void accelerate();
    void breaking();
};


#endif //FIRSTCPP_CAR_H
