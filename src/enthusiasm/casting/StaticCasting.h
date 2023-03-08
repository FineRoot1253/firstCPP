#ifndef FIRSTCPP_STATICCASTING _H
#define FIRSTCPP_STATICCASTING _H
#include <iostream>

class Car{
private:
    int fuelGauge;
public:
    Car(int fuel) : fuelGauge(fuel){}

    void showCarState(){
        std::cout<<"잔여 연료량: "<<fuelGauge<<std::endl;
    }
};

class Truck : public Car {
private:
    int freightWeight;
public:
    Truck(int fuel, int freightWeight) : Car(fuel), freightWeight(freightWeight){}

    void showTruckState(){
        showCarState();
        std::cout<<"화물의 무게: "<<freightWeight<<std::endl;
    }
};
#endif // FIRSTCPP_STATICCASTING _H

